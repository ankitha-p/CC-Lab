#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void create_prod(string);
string getFirst(char);
string getFollow(char);

map<char,vector<string> > prod;
map<char,string > first,follow;
int n;
char *order;

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
    return 0;
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
    if(prod.find(c)==prod.end()) return ans+=c; //terminal

    vector<string> v=prod[c];
    for(int i=0;i<v.size();i++)
    {
        string temp=getFirst(v[i][0]);
        if(temp=="e") ans="e"+ans;
        else ans+=temp;
    }
    return ans;
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
