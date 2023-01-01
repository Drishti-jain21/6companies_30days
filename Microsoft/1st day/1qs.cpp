//Evaluate Reverse Polish Notation

#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==0){
            return -1;
        }
        if(tokens.size()==1){
            return stoi(tokens[0]);
        }
        stack<int> calculation;
        calculation.push(stoi(tokens[0]));
        int a = stoi(tokens[0]);
        int b = 0;
        int result = 0;
        for(int i=1;i<tokens.size();i++){
            if(tokens[i]=="+"){
                result = a+b;
            }
            else if(tokens[i]=="-"){
                result = a-b;
            }
            else if(tokens[i]=="*"){
                result = a*b;
            }
            else if(tokens[i]=="/"){
                result = a/b;
            }
            else{
                if(calculation.top()!=a){
                    a = calculation.top();
                }
                calculation.push(stoi(tokens[i]));
                b = calculation.top();
                continue;
            }
            calculation.pop();
            calculation.pop();
            if(calculation.empty()){
                a = result;
                calculation.push(result);
                continue;
            }
            a = calculation.top();
            calculation.push(result);
            b = calculation.top();
            
        }
        return result;
    }
};
