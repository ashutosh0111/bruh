#include<bits/stdc++.h>
 using namespace std;
 int main(){
    stack<char> st;
    st.push('0');
    string s ="0";
    cout<<"enter the string : ";

    string ip;
    cin>> ip;
    cout<<"stack  \t\t input \t\t action  \n";
    while(ip.size()>=1){
        cout<<s<<"\t\t";
        cout<<ip<<"\t\t";
        if(ip[0]=='i'){
            if(st.top()=='0' || st.top() =='4'){
                st.push(ip[0]);
                st.push('3');
                s+=ip[0];
                s+="3";
                ip.erase(0,1);
                cout<<"shift \n";
            }
            else {
                cout<<"error ";
                break;
            }
        }
        else if(ip[0]=='+'){
            if(st.top()=='2'){
                st.push(ip[0]);
                st.push('4');
                s+=ip[0];
                s+="4";
                ip.erase(0,1);
                cout<<"shift 2 \n";

            }
            else if(st.top()=='3'){
                st.pop();
                st.pop();
                s.erase(s.size()-2,2);
                char c = st.top();
                if(st.top()=='0'|| st.top() =='4'){
                    st.push('T');
                    st.push('2');
                    s+="T";
                s+="2";
                cout<<"reduce 3 \n";
                }
                 else {
                cout<<"error ";
                break;
            }
            }
        }
        else if(ip[0]=='$'){
            if(st.top()=='1'){
                cout<<"string Accepted \n ";
                break;
            }
            else if(st.top() =='2'){
                cout<<"reduce 2 \n";
                st.pop();
                st.pop();
                s.erase(s.size()-2,2);
                if(st.top() == '0'){
                    
                    st.push('E');
                    st.push('1');
                    s+="E";
                s+="1";
                }
                else if(st.top()=='4'){
                    st.push('E');
                    st.push('5');
                    s+="E";
                s+="5";
                }
                else {
                    cout<<"break ";
                    break;
                }
            }
            else if(st.top()=='3'){
                cout<<"reduce 3\n";
                st.pop();
                st.pop();
                s.erase(s.size()-2,2);
                if(st.top() =='0' || st.top()=='4'){
                    st.push('T');
                    st.push('2');
                      s+="T";
                s+="2";
                    
                }
                else {
                    cout<<"break ";
                    break;
                }
            }
            else if(st.top()== '5')
            {
                cout<<"reduce 1 \n";
                for(int i =0 ; i<= 5 ;i++){
                    st.pop();
                    s.erase(s.size()-1,1);
                }
                if(st.top()=='0'){
                    st.push('E');
                    st.push('1');
                      s+="E";
                s+="1";
                }
                else if(st.top()=='4'){
                    st.push('E');
                    st.push('5');
                      s+="E";
                s+="5";
                }
                else {
                    cout<<"error \n";
                    break;
                }
            }
        }
        else {
            cout<<"error ";
            break;
        }
    }
 }