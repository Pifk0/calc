package calculations;
import java.util.*;

public class RPNConverter {
	private String input;
	private static final Map<String,Operations> operationMap;
	static {
		operationMap = ExpressionCalculation.getOpMap();
	}
	RPNConverter(String input) {
		this.input = input;
	}

	private static boolean hasHigherPriority(String currentOperation, String stackOperation) {
		return (operationMap.containsKey(stackOperation) && 
			   (operationMap.get(stackOperation).getPriority() >= operationMap.get(currentOperation).getPriority()));
	}
	public String convertToRPN() {
		StringBuilder output = new StringBuilder();
		Stack<String> stack = new Stack<String>();
		
		String tokens[] = input.split(" ");
		for(String token : tokens) {
			if(operationMap.containsKey(token)) {
				while( !stack.isEmpty() && hasHigherPriority(token,stack.peek())) {
					output.append(stack.pop()).append(" ");
				}
				stack.push(token);
			}
			else if (token.equals("(")) {
				stack.push(token);
			}
			else if (token.equals(")")) {
				while (!stack.peek().equals("(")) {
					output.append(stack.pop()).append(" ");
				}
				stack.pop();
			}
			else {
				output.append(token).append(" ");
			}
		}
		
		while( !stack.isEmpty()) {
			output.append(stack.pop()).append(" ");
		}
		
		return output.toString();
	}
}
