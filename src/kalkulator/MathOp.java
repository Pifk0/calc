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
    static public double Add(double x, double y){
        return (x + y);
    }
    static public double Minus(double x, double y){
        return (x - y);
    }
    static public double Multiply(double x, double y){
        return (x * y);
    }
    static public double Devide(double x, double y){
        if(0 == y)
            throw new DividedByZeroException();
        return (x/y);
    }
    static public double Power(double x, double y){
        if(0 == x && 0 == y)
            throw new PoweredZeroByZeroException();
        return Math.pow(x, y);
    }
}
