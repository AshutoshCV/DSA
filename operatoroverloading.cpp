#include<iostream>
#include<string.h>
using namespace std;
class String
{
    public:
    char str1[100];
    //char str2[100];
    public:
    void strings()
    {
        cout<<" Enter string : "<< endl;
        cin>>str1;
        //strcpy(this->str1,str1);
        // cout<< " Enter string 2: "<< endl;
        // cin>>str2;
        // strcpy(this->str2,str2);
    }
    void display()
    {
        cout<<" String is " << str1 <<endl;
    }
    String operator+(String x)
    {
        String S;
        strcat(str1,x.str1);
        strcpy(S.str1,str1);
        return S;
    }
    void lowerupper(char ch)
    {
        ch=ch-32;
        cout<<ch;
    }
};
int main()
{
   //char str1[100];
   //char str2[100];
   String A,B,C;
//    A.strings();
//    B.strings();
//    cout<<"Displaying first string "<<endl;
//    A.display();
//    cout<<"Dislaying second string "<<endl;
//    B.display();
//    C=A+B;
//    C.display();
   A.lowerupper('c');
   return 0;
}