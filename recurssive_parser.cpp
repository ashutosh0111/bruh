// ASHUTOSH RANA 2019BCSE025
// Grammer is E-> iT , T->+iT/#
/*
input format :
i+i+i$ 
i+i+$
*/

#include<bits/stdc++.h>
using namespace std ;
int num = 0;

void T(string s){
    if(s[num]=='+'){
        num++;
        //cout<<num<<endl;
        if(s[num]=='i'){
            num++;
            //cout<<num<<endl;
            T(s);
        }
        else 
        num--;
    }
    return;
}
void E (string s    ){
    
    if(s[num]=='i'){
        num++;
       // cout<<num<<endl;
        T(s);
    }
    else 
    return  ;
    
}

int main (){
    string s;

    cout<<"ENTER THE STRING \n";
    cin>>s;
    
    
   // cout<<num<<endl;
  E(s);
    
    if(s[num]=='$')
      cout<<" PARSING IS SUCCESSFUL , string accepted";
    else 
      cout<<"ERROR , string rejected ";
    
}
