using CSharp_HomeWork_3;
using System;
using System.Diagnostics.Metrics;

namespace Program;

struct Point {
    private int x { get; set; }
    private int y { get; set; }

    public Point() {
        x = 0;
        y = 0;
    }

    public Point(int _x, int _y) {
        x = _x;
        y = _y;
    }

    public void ShowData() { Console.WriteLine("X: {0}\nY: {1}", x, y); }

}

class Program {
    static void Main() {
        Point point = new Point(1, 5);
        point.ShowData();
        Counter counter = new Counter(1, 5);
        Console.WriteLine(counter.getCurrent());
        Fraction fraction1 = new Fraction(1, 5);
        fraction1.ShowData();
    }
}