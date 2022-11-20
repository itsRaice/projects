import java.util.Stack;

public class Checker {
	
	public static String check(String lineToCheck) {
		
		Stack<Character> stk = new Stack<Character>();
		int size = lineToCheck.length();
		
		//iterate through each character in string
		for (int i = 0;i<size;i++) {
			
			//current char
			char ch = lineToCheck.charAt(i);
			
			//push any open brackets onto stack
			if (ch =='[' || ch == '{' || ch =='(') {
				stk.push(ch);
			}
			
			//close bracket is found, check if any openers are in the stack
			//if there is, check if the last on stack is correct opener
			//if it is, pop the opener
			if (ch ==']') {
				
				if(stk.size()==0) {
					return ch + " at the position " + i + " does not match.";
					
				}
				else if(stk.peek() != '[') {
					return ch + " at the position " + i + " does not match.";
					
				}
				else {
					stk.pop();
				}
			}
			if (ch ==')') {
				
				if(stk.size()==0) {
					return ch + " at the position " + i + " does not match.";
					
				}
				else if(stk.peek() != '(') {
					return ch + " at the position " + i + " does not match.";
					
				}
				else {
					stk.pop();
				}
			}
			if (ch =='}') {
				
				if(stk.size()==0) {
					return ch + " at the position " + i + " does not match.";
					
				}
				else if(stk.peek() != '{') {
					return ch + " at the position " + i + " does not match.";
					
				}
				else {
					stk.pop();
				}
			}
		}
		
		//if there are leftover brackets
		//return appropriate message of missing opener
		if (stk.size() != 0) {
			if (stk.peek() == '(') {
				return ") is missing.";
			}
			if (stk.peek() == '{') {
				return "} is missing.";
			}
			if (stk.peek() == '[') {
				return "] is missing.";
			}
		}
		
		return "Everything is matched!";
	}

}
