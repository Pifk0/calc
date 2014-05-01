package calculations;

import java.util.Scanner;


public class CalcTest {
	private static void wyswietlMenu() {
		System.out.println("funkcje: abs(),log(),fact() ; q - quit");
		System.out.println("Wpisz wyrazenie do obliczenia:");
	}
	private static void run() {
		Scanner in = new Scanner(System.in);
		try {
			while(true) {
				wyswietlMenu();
				String expression = in.nextLine();
				if(expression.equals("q")) {
					System.exit(0);
				}
				ExpressionCalculation ec = new ExpressionCalculation(expression);
				ec.calculate();
				if(ec.isValid()) {
					System.out.println(ec.getExpression() +" = " +ec.getResult());
					System.out.println();
				}
				else {
					System.out.println("Wprowadzono zle wyrazenie!");
				}
			}
		} finally {
			in.close();
		}

	}
	public static void main(String[] args) {
		
		run();
	}
}
