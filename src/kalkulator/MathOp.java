/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package kalkulator;

/**
 *
 * @author 2NowakK
 */
public class MathOp extends OperationAbs{
    static public double Add(Double x, Double y){
        return (x + y);
    }
    static public double Minus(Double x, Double y){
        return (x - y);
    }
    static public double Multiply(Double x, Double y){
        return (x * y);
    }
    static public double Divide(Double x, Double y){
        if(0 == y)
            throw new DividedByZeroException("Dzielenie przez zero - ");
        return (x/y);
    }
    static public double Power(Double x, Double y){
        if(0 == x && 0 == y)
            throw new PoweredZeroByZeroException();
        return Math.pow(x, y);
    }
}
