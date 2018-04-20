#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<sstream>
#include<unordered_set>
#include<vector>
using namespace std;

unordered_set<string> keywords={"auto","break","case","char","const","continue","default","do",
	"double","else","enum","extern","float","for","if","int","long","register","return","short",
	"signed","sizeof","static","struct","switch","typedef","unsigned","void","while"};
unordered_set<string> operators={"+","-","=","<",">","*","%","/"};
unordered_set<string> symbols={";","{","}","(",")","]","@","!","["};

class output{
public:
    string token,lexeme,pattern;
    output(string a,string b,string c){token=a;lexeme=b;pattern=c;} //constructor
};

int main(){

    string filename;
    cout<<"Enter the file name:\t";
    cin>>filename;
    ifstream inFile;
    inFile.open(filename.c_str());
    string str;
    vector<output> v;

    while(getline(inFile,str)){
		
		int len=str.length(),i=0;
		do{
			char c=str[i];
			string identifier="",num="",target="";
			stringstream ss;
			bool word=false,number=false;
			while((c>=65 && c<=90)||(c>=97 && c<=122)){
				identifier+=c;
				if(i+1==len) break;
				c=str[++i];
				word=true;
			}
			if(word){
					if(keywords.find(identifier)==keywords.end())
						v.push_back(output("id",identifier,"variable"));
					else
						v.push_back(output("keyword",identifier,"keywords like if,const etc"));
			}
			while(c>=48 && c<=57){
				num+=c;
				if(i+1==len) break;
				c=str[++i];
				number=true;
			}
			if(number) v.push_back(output("num",num,"any numeric constant"));
			ss<<c;
			ss>>target;
			if(operators.find(target)!=operators.end())
				v.push_back(output("operators",target,"like +,-,*,/ etc"));
			if(symbols.find(target)!=symbols.end())
				v.push_back(output("symbol",target,"like ;,:,@,{,etc"));
			if(c=='"'){
				do{
					if(i+1==len) break;
					c=str[++i];
				}while(c!='"');
			}
			i++;

		}while(i<len);
    }
    cout<<"TOKEN\tLEXEME\tPATTERN\n";
    vector<output>::iterator itr;
    for (itr= v.begin(); itr != v.end(); ++itr){
        output temp=*itr;

        cout <<left<<setw(15)<<temp.token <<left<<setw(15)<<temp.lexeme<<"\t"<<temp.pattern<<endl;
    }
    return 0;
}


