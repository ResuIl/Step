using System;

namespace ConsoleApp1
{
    enum MathOperator
    {
        Add,
        Subtract,
        Multiply,
        Divide,
    };
    class Program
    {

        static void Main(string[] args)
        {
            int Add(int a, int b) { return a + b; }

            int Subtract(int a, int b) { return a - b; }

            int Multiply(int a, int b) { return a * b; }

            int Divide(int a, int b) {
                if (a == 0 || b == 0)
                {
                    Console.Write("ERROR\n");
                    return 0;
                }
                return a / b; 
            }

            while (true)
            {
                Console.Write("Enter A: ");
                int A = Convert.ToInt32(Console.ReadLine());
                Console.Write("Enter B: ");
                int B = Convert.ToInt32(Console.ReadLine());
                Console.Write($"1) {A} + {B}\n2) {A} - {B}\n3) {A} * {B}\n4) {A} / {B}\n5) Exit\n");
                Console.Write("Make Choice: ");
                int op = Convert.ToInt32(Console.ReadLine());

                switch (op - 1)
                {
                    case 0:
                        Console.Write(Add(A, B) + Environment.NewLine);
                        break;
                    case 1:
                        Console.Write(Subtract(A, B) + Environment.NewLine);
                        break;
                    case 2:
                        Console.Write(Multiply(A, B) + Environment.NewLine);
                        break;
                    case 3:
                        Console.Write(Divide(A, B) + Environment.NewLine);
                        break;
                    case 4:
                        System.Environment.Exit(1);
                        break;
                }
            }

        }
    }
}
