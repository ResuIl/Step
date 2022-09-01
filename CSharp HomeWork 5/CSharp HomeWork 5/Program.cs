using System.Numerics;

class Card
{
    public string PAN { get; }
    public string PIN { get; }
    public string CVC { get; }
    public string ExpireDate { get; }
    public int Balance { get; set; }
    public List<string> Statements = new();

    public Card(string pAN, string pIN, string cVC, string expireDate, int balance)
    {
        if (pAN.Length > 0 && pIN.Length > 0 && cVC.Length > 0 && expireDate.Length > 0)
        {
            PAN = pAN;
            PIN = pIN;
            if (cVC.Length == 3)
                CVC = cVC;
            else
            {
                Random rnd = new Random();
                CVC = rnd.Next(100, 999).ToString();
            }
            ExpireDate = expireDate;
            Balance = balance;
        }

    }
}

class User
{
    public string FullName { get; }
    public Card Creditcard { get; }

    public User(string fullName, Card creditcard)
    {
        FullName = fullName;
        Creditcard = creditcard;
    }

    public override string ToString()
    {
        return "Fullname: " + FullName;
    }
}

class Program
{
    static void Main()
    {
        List<User> users = new(); 

        users.Add(new User("Resul Black", new Card("4169731313132121", "2111", "721", "10/26", 100)));
        users.Add(new User("Mark William", new Card("5113731313132121", "9981", "251", "10/22", 500)));
        users.Add(new User("Jordan Diamond", new Card("7313731313132121", "9898", "333", "10/26", 2000)));
        
        int listLeng = users.Count;
        int found = -1;

        while (true)
        {
            Console.WriteLine("Enter pin:");
            string pin = Console.ReadLine();

            for (int i = 0; i < listLeng; i++)
            {
                if (users[i].Creditcard.PIN == pin)
                    found = i;
            }

            if (found != -1)
            {
                Console.WriteLine($"Welcome " + users[found].FullName);
                Console.WriteLine("1) Balance\n2) Withdraw\n3) Statements\n4) Transfer\n5) Exit");

                while (true)
                {
                    Console.WriteLine("Make Choice:");
                    string choice = Console.ReadLine();
                    if (choice == "1")
                        Console.WriteLine($"Balance: " + users[found].Creditcard.Balance);
                    else if (choice == "2")
                    {
                        Console.WriteLine($"1) 10 AZN\n2) 20 AZN\n3) 50 AZN\n4) 100 AZN\n5) Diger");
                        string choice2 = Console.ReadLine();
                        if (choice2 == "1")
                        {

                            if (users[found].Creditcard.Balance - 10 > 0)
                            {
                                users[found].Creditcard.Balance -= 10;
                                users[found].Creditcard.Statements.Add("10 AZN Successfully Withdrawed. " + DateTime.Now);
                                Console.WriteLine($"10 AZN Successfully Withdrawed.");
                            }
                            else
                                Console.WriteLine($"You Dont Have Enoug Money");

                        }
                        else if (choice2 == "2")
                        {
                            if (users[found].Creditcard.Balance - 12 > 0)
                            {
                                users[found].Creditcard.Balance -= 20;
                                users[found].Creditcard.Statements.Add("20 AZN Successfully Withdrawed. " + DateTime.Now);
                                Console.WriteLine($"20 AZN Successfully Withdrawed.");
                            }
                            else
                                Console.WriteLine($"You Dont Have Enoug Money");
                        }
                        else if (choice2 == "3")
                        {
                            if (users[found].Creditcard.Balance - 50 > 0)
                            {
                                users[found].Creditcard.Balance -= 50;
                                users[found].Creditcard.Statements.Add("50 AZN Successfully Withdrawed. " + DateTime.Now);
                                Console.WriteLine($"50 AZN Successfully Withdrawed.");
                            }
                            else
                                Console.WriteLine($"You Dont Have Enoug Money");
                        }
                        else if (choice2 == "4")
                        {
                            if (users[found].Creditcard.Balance - 100 > 0)
                            {
                                users[found].Creditcard.Balance -= 100;
                                users[found].Creditcard.Statements.Add("100 AZN Successfully Withdrawed. " + DateTime.Now);
                                Console.WriteLine($"100 AZN Successfully Withdrawed.");
                            }
                            else
                                Console.WriteLine($"You Dont Have Enoug Money");
                        }
                        else if (choice2 == "5")
                        {
                            string money = Console.ReadLine();
                            if (users[found].Creditcard.Balance - Int32.Parse(money) > 0)
                            {
                                users[found].Creditcard.Balance -= Int32.Parse(money);
                                users[found].Creditcard.Statements.Add($"{Int32.Parse(money)} AZN Successfully Withdrawed. " + DateTime.Now);
                                Console.WriteLine($"{Int32.Parse(money)} AZN Successfully Withdrawed.");
                            }
                            else
                                Console.WriteLine($"You Dont Have Enoug Money");
                        }
                    }
                    else if (choice == "3")
                    {
                        foreach (string statement in users[found].Creditcard.Statements)
                            Console.WriteLine(statement);
                    }
                    else if (choice == "4")
                    {
                        Console.WriteLine("Enter PIN: ");
                        string transferTo = Console.ReadLine();
                        Console.WriteLine("Enter Transfer Amount: ");
                        string transferAmount = Console.ReadLine();
                        bool foundd = false;
                        for (int i = 0; i < listLeng; i++)
                        {
                            if (users[i].Creditcard.PIN == transferTo)
                            {
                                foundd = true;
                                if (users[found].Creditcard.Balance - Int32.Parse(transferAmount) > 0)
                                {
                                    users[found].Creditcard.Balance -= Int32.Parse(transferAmount);
                                    users[found].Creditcard.Statements.Add($"{Int32.Parse(transferAmount)} AZN Successfully Transfered to {users[i].FullName}. " + DateTime.Now);
                                    users[i].Creditcard.Balance += Int32.Parse(transferAmount);
                                    users[i].Creditcard.Statements.Add($"{Int32.Parse(transferAmount)} AZN Successfully Transfered From {users[found].FullName}. " + DateTime.Now);
                                    Console.WriteLine("Successfully Transfered.");
                                }
                                else
                                    Console.WriteLine("You Dont Have Enough Money.");
                            }
                        }
                        if (!foundd) 
                            Console.WriteLine("Account Not Found");
                    }
                    else if (choice == "5")
                        break;
                    else
                    {
                        Console.Clear();
                        Console.WriteLine($"Welcome " + users[found].FullName);
                        Console.WriteLine("1) Balance\n2) Withdraw\n3) Statements\n4) Transfer\n5) Exit");
                    }
                }
            }
            else
                Console.WriteLine("Incorrect Pin!");
        }     
    }
}