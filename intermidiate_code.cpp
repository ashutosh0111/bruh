//2019BCSE025 ASHUTOSH RANA 

#include<bits/stdc++.h>
using namespace std ;
int main(){
    cout<<"operation can be performed of + , / ,*,- and \n in single curly braces and single digit number  \n ";
    cout<<"enter the expression ";
    string s ;
     cin>> s;
     char z= s[0];
     s.erase(0,2);
     int k =0 , i=0 ;
     string s1="";
     if(s[0]=='-'){
        char c = char(65+k);
        string A = "";
        A+=s[0];
        A+=s[1];
        s.erase(0,2);
        s=c+s;
        k++;
        cout<<c<<"= "<<A<<endl;
     }
     while(i< s.size()){
        if(s[i]=='('){
            string A="";
            i++;
            while(s[i]!= ')'){
                A=A+s[i];
                i++;

            }
            int x = 65+k;
            k++;
            char c = char(x);
            cout<<c<<" = "<<A<<endl;
            s1=s1+c;
            i++;


        }
        else {
            s1=s1+s[i];
            i++;
        }
     }
     //cout<<s1;
     // now to simply apply BODMAS rule ;
     int op=0;
     for(int i =0 ; i< s1.size() ; i++){
        if(s1[i]=='+' || s1[i]=='-' || s1[i]=='*' || s1[i]=='/' ){
            op++;
        }
     }
     i=0;
     
     
     // for division 
     stack<char> stk;
     
     while(i<s1.size()){
         if(s1[i]=='/'){
                char y = stk.top();
                stk.pop();
                int x = 65+k;
                k++;
            char c = char(x);
            char z = s1[++i];
                cout<<c <<"= "<<y<<"/"<<z<<endl;
                stk.push(c);
                i++;
            }
            else 
            {stk.push(s1[i]);
            i++;
            }
     }
    
     s1="";
     while(!stk.empty()){
         s1=stk.top()+s1;
         stk.pop();
     }
     //cout<<s1;
     // multiplication 
     i=0;
      while(i<s1.size()){
         if(s1[i]=='*'){
                char y = stk.top();
                stk.pop();
                int x = 65+k;
                k++;
            char c = char(x);
            char z = s1[++i];
                cout<<c <<"= "<<y<<"*"<<z<<endl;
                stk.push(c);
                i++;
            }
            else 
            {stk.push(s1[i]);
            i++;
            }
     }
     
     s1="";
     while(!stk.empty()){
         s1=stk.top()+s1;
         stk.pop();
     }
     i=0;
     // for addition 
      while(i<s1.size()){
         if(s1[i]=='+'){
                char y = stk.top();
                stk.pop();
                int x = 65+k;
                k++;
            char c = char(x);
            char z = s1[++i];
                cout<<c <<"= "<<y<<"+"<<z<<endl;
                stk.push(c);
                i++;
            }
            else 
            {stk.push(s1[i]);
            i++;
            }
     }
     //cout<<endl;
     //cout<<s1<<endl;
     s1="";
     while(!stk.empty()){
         s1=stk.top()+s1;
         stk.pop();
     }
     i=0;
     // for substraction 
      while(i<s1.size()){
         if(s1[i]=='-'){
                char y = stk.top();
                stk.pop();
                int x = 65+k;
                k++;
            char c = char(x);
            char z = s1[++i];
                cout<<c <<"= "<<y<<"-"<<z<<endl;
                stk.push(c);
                i++;
            }
            else 
            {
                stk.push(s1[i]);
            i++;
            }
     }
     s1="";
     while(!stk.empty()){
         s1=stk.top()+s1;
         stk.pop();
     }
     cout<<z<<" = "<<char(65+k-1)<<endl;
}