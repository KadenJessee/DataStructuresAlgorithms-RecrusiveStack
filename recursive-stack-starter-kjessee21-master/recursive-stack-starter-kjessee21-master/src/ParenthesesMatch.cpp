#include "ParenthesesMatch.h"
#include <iostream>
#include <stack>
#include <string>

bool parenthesesMatch(const char* str){
   Stack<char> temp;
   int counter = 0;
   //get counter from str
   while(str[counter])
   {
       counter++;
   }
   for(int i = 0; i < counter; i++){
       //if parenthesis, push
        if(str[i] == '('){
            temp.push(str[i]);
        }//check for closing
        else if(str[i] == ')'){
            //if empty return false
            if(temp.empty()){
                return false;
            }//else pop opening
            else{
                temp.pop();
            }
        }
   }
   //if empty, then true (since you pop the method
   if(temp.empty()){
       return true;
   }//else false
   else{
       return false;
   }
}
