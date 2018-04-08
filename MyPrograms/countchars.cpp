#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main(){
    int chars=0,tabs=0,spaces=0,lines=0;
    string filename;
    cout<<"Enter the file name:\t";
    cin>>filename;
    ifstream inFile;
    inFile.open(filename.c_str());
    string str;
    while(getline(inFile,str)){
        for(int i=0;i<str.length();i++){
            if(str[i]=='\t')tabs++;
            else if(str[i]==' ')spaces++;
            chars++;
        }
        lines++;
    }
    inFile.close();
    cout<<"The number of characters is:  "<<chars<<endl;
    cout<<"The number of lines is:  "<<lines<<endl;
    cout<<"The number of tabs is:  "<<tabs<<endl;
    cout<<"The number of spaces is:  "<<spaces<<endl;
    return 0;
}


