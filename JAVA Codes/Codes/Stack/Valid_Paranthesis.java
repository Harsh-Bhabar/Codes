package Codes.Stack;

public class Valid_Paranthesis {
	
}

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        
        if(s.length() % 2 != 0){
            return false;
        }

        for(int i=0; i<s.length(); i++){
            char curr = s.charAt(i);

            if(curr == '{' || curr == '[' || curr == '('){
                st.push(curr);
            }else{
                if(!st.isEmpty() && (   
                    (curr == ']' && st.peek() == '[') ||    
                    (curr == ')' && st.peek() == '(') ||
                    (curr == '}' && st.peek() == '{')
                )){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        return st.isEmpty();

    }
}