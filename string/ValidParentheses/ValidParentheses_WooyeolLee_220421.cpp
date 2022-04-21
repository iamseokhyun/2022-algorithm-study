/* 1st try
- Not an impressive runtime performance
- In case of a string s = ¡°([{]([])])¡±, we can find s is not valid at 4th character but this algorithm does not implement it.
*/

bool isValid(string s) {
    if(s.length()&1) return false;     
    
    stack<char> brackets; 
    for(char c : s)
        checkBracketsPair(brackets, s, c);
    if(brackets.empty()) return true;  
    return false;    
}    

void checkBracketsPair(stack<char>& brackets, string s, char c){    
    if(brackets.empty()) {            
        brackets.push(c);
        return;       
    }           
    char top = brackets.top();
    if(top == '(' && c == ')')  
        brackets.pop();       
    else if(top == '[' && c == ']')  
        brackets.pop();      
    else if(top == '{' && c == '}')   
        brackets.pop();      
    else brackets.push(c);    
}


/* 2nd try
 - Revised version
 */
 
 bool isValid(string s) {        
    if(s.length()&1) return false;

    stack<char> brackets;        
    for(char c : s){            
        if(c=='('||c=='['||c=='{')
            brackets.push(c);           
        else if(brackets.empty()) 
            return false;            
        else if(brackets.top()=='(' && c==')')
            brackets.pop();            
        else if(brackets.top()=='[' && c==']') 
            brackets.pop();           
        else if(brackets.top()=='{' && c=='}') 
            brackets.pop();           
        else return false;       
    } // quite messy for-loop :(

    if(brackets.empty()) return true; 
    return false;    
}
