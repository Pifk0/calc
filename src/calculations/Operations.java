package calculations;

public interface Operations {
	public int getPriority();
	public String getFuncName();
}

enum Operators implements Operations {
	ADD(1,"Add"), SUBTRACT(2,"Minus"), MULTIPLY(3,"Multiply"), DIVIDE(4,"Divide"), POV(5,"Power");
	final int priority;
	final String fname;
	Operators(int priority,String fname) {
		this.priority = priority;
		this.fname = fname;
	}
	public int getPriority() {
		return this.priority;
	}
	public String getFuncName() {
		return this.fname;
	}
}

enum Functions implements Operations {
	LOG(6,"Log"), ABS(6,"Abs"), FACT(6,"Fact");
	final int priority;
	final String fname;
	Functions(int priority,String fname) {
		this.priority = priority;
		this.fname = fname;
	}
	public int getPriority() {
		return this.priority;
	}
	public String getFuncName() {
		return this.fname;
	}
}
