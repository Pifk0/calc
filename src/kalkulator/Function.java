/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package kalkulator;

/**
 *
 * @author 2NowakK
 */
public class Function extends OperationAbs{
    static public double Log(Double x){
    	if(x <= 0) {
    		throw new NegativeLogException("Ln z liczby ujemnej - ");
    	}
        return Math.log(x);
    }
    static public double Sqrt(Double x){
        return Math.sqrt(x);
    }
    static public double Abs(Double x){
        return Math.abs(x);
    }
    static public double Fact(Double x) {
    	if (x < 1)
    		return 1;
    	else
    		return x * Fact(x - 1);
    }
}
