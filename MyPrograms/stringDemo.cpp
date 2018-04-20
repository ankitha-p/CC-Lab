#include <iostream>
#include <string>

int main () {
   std::string base="this is a test string.";
   std::string str2="n example";
   std::string str3="sample phrase";
   std::string str4="useful.";

   std::string str=base;
   str.replace(9,5,str2);
   str.replace(19,6,str3,7,6);
   str.replace(8,10,"just a");
   str.replace(8,6,"a shorty",7);
   str.replace(22,1,3,'!');

   str.replace(str.begin(),str.end()-3,str3);
   str.replace(str.begin(),str.begin()+6,"replace");
   str.replace(str.begin()+8,str.begin()+14,"is coolness",7);
   str.replace(str.begin()+12,str.end()-4,4,'o');
   str.replace(str.begin()+11,str.end(),str4.begin(),str4.end());
   std::cout << str << '\n';
   return 0;
}
