using System;

delegate void Func(string str);

class MyClass
{
    public string String { get; set; }
    public MyClass(string str)
    {
        String = str;
    }
    public void Space(string str) => Console.WriteLine(string.Join('_', str.ToCharArray()));
    public void Reverse(string str)
    {
        char[] charArray = str.ToCharArray();
        Array.Reverse(charArray);
        Console.WriteLine(new string(charArray));
    }
}

class Run
{
    public void runFunc(Func delegates, string str)
    {
        foreach (var func in delegates.GetInvocationList())
            func.DynamicInvoke(str);
    }
}


class Program 
{
    public static void Main()
    {
        Console.WriteLine("Enter string: ");

        var str = Console.ReadLine();
        MyClass cls = new MyClass(str);



        Func funcDell = null!;
        funcDell += cls.Space;
        funcDell += cls.Reverse;


        Run run = new Run();
        run.runFunc(funcDell, str);
    }
}
