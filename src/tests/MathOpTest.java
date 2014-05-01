package tests;

import junit.framework.Assert;
import junit.framework.TestCase;
import kalkulator.MathOp;

public class MathOpTest extends TestCase {

    public void testAdd() throws Exception {
        Assert.assertEquals(-1.00, MathOp.Add(1.0, -2.0));
    }

    public void testMinus() throws Exception {
        assertEquals(3.00, MathOp.Minus(1.0, -2.0));
    }

    public void testMultiply() throws Exception {
        assertEquals(-4.00, MathOp.Multiply(2.0, -2.0));
    }

    public void testDivide() throws Exception {
        assertEquals(0.33, MathOp.Divide(1.0, 3.0));
    }

    public void testPower() throws Exception {
        assertEquals(MathOp.Power(2.0, 2.0), 4.00);
    }
}