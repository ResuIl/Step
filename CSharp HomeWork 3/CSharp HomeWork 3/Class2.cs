using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_HomeWork_3 {
    internal class Fraction {

        private int numerator { get; set; }
        private int denominator { get; set; }

        public Fraction() {
            numerator = 0;
            denominator = 0;
        }

        public Fraction(int _numerator, int _denominator) {
            numerator = _numerator;
            denominator = _denominator;
        }

        public Fraction Multiply(in Fraction other) {
            Fraction f = new Fraction(numerator * other.numerator, denominator * other.denominator);
            return f;

        }

        public Fraction Divide(in Fraction other) {
            if (other.denominator != 0)
            {
                Fraction f = new Fraction(numerator + other.numerator, denominator + other.denominator);
                return f;
            }
            return this;

        }

        public Fraction Add(in Fraction other) {
            Fraction f = new Fraction(numerator + other.numerator, denominator + other.denominator);
            return f;
        }

        public Fraction Subtract(in Fraction other) {

            Fraction f = new Fraction(numerator - other.numerator, denominator - other.denominator);
            return f;
        }

        public void ShowData() { Console.WriteLine($"Numerator: {numerator}\nDenomirator: {denominator}"); }

    }
}
