using System.Collections.Generic;

class DictionaryClass
{
    public string[][] Dict { get; set; }
    public DictionaryClass()
    {
        Dict = new string[10][];
    }
    public string[] this[int index]
    {
        get => Dict[index];
        set => Dict[index] = value;
    }
}
class Article
{
    private string ProductName { get; set; }
    private Guid ProductCode { get; set; }
    private double Price { get; set; }

    public Article(string productName, Guid productCode, double price)
    {
        ProductName = productName;
        ProductCode = productCode;
        Price = price;
    }
    public static double operator +(Article a1, Article a2)
    {
        return a1.Price + a2.Price;
    }
    public static double operator -(Article a1, Article a2)
    {
        return a1.Price - a2.Price;
    }
    public static double operator *(Article a1, Article a2)
    {
        return a1.Price * a2.Price;
    }
    public static double operator /(Article a1, Article a2)
    {
        if (a2.Price != 0)
            return a1.Price / a2.Price;
        throw new DivideByZeroException();
    }
    public static Article operator ++(Article a)
    {
        a.Price++;
        return a;
    }
    public static Article operator --(Article a)
    {
        a.Price--;
        return a;
    }
    public static bool operator ==(Article a1, Article a2)
    {
        return a1.Price == a2.Price;
    }
    public static bool operator !=(Article a1, Article a2)
    {
        return a1.Price != a2.Price;
    }
    public static bool operator >(Article a1, Article a2)
    {
        return a1.Price > a2.Price;
    }
    public static bool operator <(Article a1, Article a2)
    {
        return a1.Price < a2.Price;
    }
    public override string ToString()
    {
        return ($"Product name: {ProductName}, Product code: {ProductCode}, Price: {Price}");
    }
}
struct Client
{
    public Guid ClientCode { get; set; }
    public string FullName { get; set; }
    public string Address { get; set; }
    public string Phone { get; set; }
    public int NumberOfOrder { get; set; }
    public int TotalAmount { get; set; }
    public Client(Guid clientCode, string fullName, string address, string phone, int numberOfOrder, int totalAmount)
    {
        ClientCode = clientCode;
        FullName = fullName;
        Address = address;
        Phone = phone;
        NumberOfOrder = numberOfOrder;
        TotalAmount = totalAmount;
    }

    public static double operator +(Client q1, Client q2)
    {
        return q1.NumberOfOrder + q2.NumberOfOrder;
    }

    public static double operator -(Client q1, Client q2)
    {
        return q1.NumberOfOrder - q2.NumberOfOrder;
    }
    public static double operator *(Client q1, Client q2)
    {
        return q1.NumberOfOrder * q2.NumberOfOrder;
    }

    public static double operator /(Client q1, Client q2)
    {
        if (q2.NumberOfOrder != 0)
            return q1.NumberOfOrder / q2.NumberOfOrder;
        throw new DivideByZeroException();
    }
    public static Client operator ++(Client a)
    {
        a.NumberOfOrder++;
        return a;
    }
    public static Client operator --(Client a)
    {
        a.NumberOfOrder--;
        return a;
    }
    public static bool operator ==(Client q1, Client q2)
    {
        return q1.NumberOfOrder == q2.NumberOfOrder;
    }
    public static bool operator !=(Client q1, Client q2)
    {
        return q1.NumberOfOrder != q2.NumberOfOrder;
    }
    public static bool operator >(Client q1, Client q2)
    {
        return q1.NumberOfOrder > q2.NumberOfOrder;
    }
    public static bool operator <(Client q1, Client q2)
    {
        return q1.NumberOfOrder < q2.NumberOfOrder;
    }
    public override string ToString()
    {
        return ($"Client Code {ClientCode} Full name: {FullName} Adress: {Address} Phone: {Phone} Number of Order: {NumberOfOrder} Total amount: {TotalAmount}");
    }
}

class Program
{
    static void Main()
    {
        DictionaryClass Dict = new();
        Dict[0] = new string[2] { "book", "Kitab" };
        Dict[1] = new string[2] { "pen", "Qelem" };
        Dict[2] = new string[2] { "house", "Ev" };
        Dict[3] = new string[2] { "apple", "Alma" };

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 2; j++)
                Console.WriteLine(Dict[i][j]);
            Console.WriteLine();
        }
    }
}