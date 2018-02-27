#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;
/*
E->TP
P->+TP|e
T->FQ
Q->*FQ|e
F->(E)|e
*/
void create_prod(string);
string getFirst(char);
string getFollow(char);
void getLL(char);
void printLLTable();
map<char,vector<string> > prod;
map<char,string > first,follow;
int n;
char *order;
map<char,string> terminals;
map<char,string> :: iterator itr;

int main()
{
    cout<<"Enter the number of productions: ";
    cin>>n;
    order=new char[n];
    cout<<"Enter the productions:\n";
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        order[i]=s[0];
        create_prod(s);
    }
    for(int i=0;i<n;i++)
    {
        first[order[i]]=getFirst(order[i]);
        cout<<"FIRST("<<order[i]<<") = "<<first[order[i]]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        follow[order[i]]=getFollow(order[i]);
        cout<<"FOLLOW("<<order[i]<<") = "<<follow[order[i]]<<endl;
    }
    printLLTable();
    return 0;
}
void printLLTable()
{
    cout<<"\n\t\tLL(1) PARSING TABLE\n";
    cout<<setw(10)<<"|";
    terminals['$']="";
    for(itr=terminals.begin();itr!=terminals.end();itr++) cout<<left<<setw(10)<<itr->first;
    cout.fill('-');
    cout<<setw((terminals.size()+1)*10)<<"\n";
    cout.fill(' ');
    cout<<endl;
    for(int i=0;i<n;i++) getLL(order[i]);
    cout<<endl;
}

string getFollow(char c)
{
    string ans="";
    if(c==order[0]) ans+="$";
    for(int i=0;i<n;i++)
    {
        char head=order[i];
        vector<string> v=prod[head];
        for(int j=0;j<v.size();j++)
        {
            string temp=v[j];
            int found=temp.find(c);
            if(found!= std::string::npos)
            {
                if(found+1!=temp.length())
                {
                    string newtemp=getFirst(temp[found+1]);
                    if(newtemp[0]=='e')
                    {
                        newtemp=newtemp.substr(1);
                        if(head!=c) newtemp+=getFollow(head);
                    }
                    ans+=newtemp;
                }
                else    if(head!=c) ans+=getFollow(head);
            }
        }
    }
    //remove duplicates from the answer
    sort(ans.begin(),ans.end());
    string temp=ans;
    ans.resize( std::distance(ans.begin(),std::unique_copy(temp.begin(),temp.end(),ans.begin())));
    return ans;
}

string getFirst(char c)
{
    string ans="";
    if(prod.find(c)==prod.end())
    {
        if(c!='e') terminals[c]="";
        ans+=c;
        first[c]=ans;
        return ans; //terminal
    }
    vector<string> v=prod[c];
    for(int i=0;i<v.size();i++)
    {
        string temp=getFirst(v[i][0]);
        if(temp=="e") ans="e"+ans;
        else ans+=temp;
    }
    return ans;
}

void getLL(char c)
{
    cout<<left<<setw(9)<<c<<"|";
    vector<string> v=prod[c];
    string fir=first[c],fol=follow[c],ans="";
    for(int i=0;i<fir.length();i++)
    {
        char ch=fir[i];
        if(ch=='e')
            for(int i=0;i<fol.length();i++)
                {
                    ans=ans+c+"->e";
                    terminals[fol[i]]=ans;
                    ans="";
                }
        else
        {
            for(int j=0;j<v.size();j++)
            {
                string temp=first[v[j][0]];
                if(temp.find(ch)!=std::string::npos)
                {
                    ans=ans+c+"->"+v[j];
                    terminals[ch]=ans;
                    ans="";
                }
            }
        }
    }
    for(itr=terminals.begin();itr!=terminals.end();itr++) cout<<left<<setw(10)<<terminals[itr->first];
    cout<<endl;
    for(itr=terminals.begin();itr!=terminals.end();itr++) terminals[itr->first]="";
}

void create_prod(string s)
{
    int i=3;
    string in="";
    vector<string> v;
    while(i<s.length())
    {
        if(s[i]=='|')
        {
            v.push_back(in); in=""; i++;
        }
        else    in+=s[i++];
    }
    v.push_back(in);
    prod[s[0]]=v;
}
