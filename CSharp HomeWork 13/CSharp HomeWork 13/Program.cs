using CSharp_HomeWork_13;
using System.Linq;
using System.Xml.Linq;
using Serilog;
using Newtonsoft.Json;
using System.Net.Mail;

// Tarixe Göre Rezer Sistemi

static class MainClass
{
    static Doctor[] Pediatria = {};
    static Doctor[] Travmatologiya = {};
    static Doctor[] Stamotologiya = {};

    static public void JsonDeSerialize()
    {
        var PediatriajsonString = File.ReadAllText("Pediatria.json");
        Pediatria = JsonConvert.DeserializeObject<Doctor[]>(PediatriajsonString);
        var TravmatologiyajsonString = File.ReadAllText("Travmatologiya.json");
        Travmatologiya = JsonConvert.DeserializeObject<Doctor[]>(TravmatologiyajsonString);
        var StamotologiyajsonString = File.ReadAllText("Stamotologiya.json");
        Stamotologiya = JsonConvert.DeserializeObject<Doctor[]>(StamotologiyajsonString);
    }
    static public void JsonSerialize()
    {
        var PediatriajsonString = JsonConvert.SerializeObject(Pediatria, Newtonsoft.Json.Formatting.Indented);
        File.WriteAllText("Pediatria.json", PediatriajsonString);
        var TravmatologiyajsonString = JsonConvert.SerializeObject(Travmatologiya, Newtonsoft.Json.Formatting.Indented);
        File.WriteAllText("Travmatologiya.json", TravmatologiyajsonString);
        var StamotologiyajsonString = JsonConvert.SerializeObject(Stamotologiya, Newtonsoft.Json.Formatting.Indented);
        File.WriteAllText("Stamotologiya.json", StamotologiyajsonString);
    }
    
    static public int Run(string type, string name, string surname, string day, string month, string year)
    {
        
        if (type == "1")
        {
            for (int i = 0; i < Pediatria.Length; i++)
                Console.WriteLine($"{Pediatria[i]}\n");

            int time = Int32.Parse(Console.ReadLine());
            for (int j = 0; j < Pediatria[time - 1].Worktime.Count; j++)
            {
                if (Pediatria[time - 1].Reserved.Contains($"{day}.{month}.{year}:{Pediatria[time - 1].Worktime[j]}"))
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.BackgroundColor = ConsoleColor.White;
                    Console.WriteLine($"{j + 1}) {Pediatria[time - 1].Worktime[j]}");
                }
                else
                {
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.BackgroundColor = ConsoleColor.Black;
                    Console.WriteLine($"{j + 1}) {Pediatria[time - 1].Worktime[j]}");
                }
            }
            int reservedtime = Int32.Parse(Console.ReadLine());
            if (!Pediatria[time - 1].Reserved.Contains($"{day}.{month}.{year}:{Pediatria[time - 1].Worktime[reservedtime - 1]}"))
            {
                Pediatria[time - 1].Reserved.Add($"{day}.{month}.{year}:{Pediatria[time - 1].Worktime[reservedtime - 1]}");
                Console.Clear();
                Log.Information($"Successfully Reserved By {name} {surname} at {Stamotologiya[time - 1].Worktime[reservedtime - 1]} Pediatria");
                MainClass.JsonSerialize();
                return 1;
            }
            Console.Clear();
            Console.WriteLine("Reservation Failed.");
            Log.Information($"Reservation Failed. By {name} {surname} Non Empty Time.");
            return 1;
        } 
        else if (type == "2")
        {
            for (int i = 0; i < Travmatologiya.Length; i++)
                Console.WriteLine($"{Travmatologiya[i]}\n");

            int time = Int32.Parse(Console.ReadLine());
            for (int j = 0; j < Travmatologiya[time - 1].Worktime.Count; j++)
            {
                if (Travmatologiya[time - 1].Reserved.Contains($"{day}.{month}.{year}:{Travmatologiya[time - 1].Worktime[j]}"))
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.BackgroundColor = ConsoleColor.White;
                    Console.WriteLine($"{j + 1}) {Travmatologiya[time - 1].Worktime[j]}");
                }
                else
                {
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.BackgroundColor = ConsoleColor.Black;
                    Console.WriteLine($"{j + 1}) {Travmatologiya[time - 1].Worktime[j]}");
                }
            }
            int reservedtime = Int32.Parse(Console.ReadLine());
            if (!Travmatologiya[time - 1].Reserved.Contains($"{day}.{month}.{year}:{Travmatologiya[time - 1].Worktime[reservedtime - 1]}"))
            {
                Travmatologiya[time - 1].Reserved.Add($"{day}.{month}.{year}:{Travmatologiya[time - 1].Worktime[reservedtime - 1]}");
                Console.Clear();
                Log.Information($"Successfully Reserved By {name} {surname} at {Travmatologiya[time - 1].Worktime[reservedtime - 1]} Travmatologiya");
                MainClass.JsonSerialize();
                return 1;
            }
            Console.Clear();
            Log.Information($"Reservation Failed. By {name} {surname} Non Empty Time.");
            return 1;
        } 
        else
        {
            for (int i = 0; i < Stamotologiya.Length; i++)
                Console.WriteLine($"{Stamotologiya[i]}\n");

            int time = Int32.Parse(Console.ReadLine());
            for (int j = 0; j < Stamotologiya[time - 1].Worktime.Count; j++)
            {
                if (Stamotologiya[time - 1].Reserved.Contains($"{day}.{month}.{year}:{Stamotologiya[time - 1].Worktime[j]}"))
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.BackgroundColor = ConsoleColor.White;
                    Console.WriteLine($"{j + 1}) {Stamotologiya[time - 1].Worktime[j]}");
                }
                else
                {
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.BackgroundColor = ConsoleColor.Black;
                    Console.WriteLine($"{j + 1}) {Stamotologiya[time - 1].Worktime[j]}");
                }
            }
            int reservedtime = Int32.Parse(Console.ReadLine());
            if (!Stamotologiya[time - 1].Reserved.Contains($"{day}.{month}.{year}:{Stamotologiya[time - 1].Worktime[reservedtime - 1]}"))
            {
                Stamotologiya[time - 1].Reserved.Add($"{day}.{month}.{year}:{Stamotologiya[time - 1].Worktime[reservedtime - 1]}");
                Console.Clear();
                Log.Information($"Successfully Reserved By {name} {surname} at {Stamotologiya[time - 1].Worktime[reservedtime - 1]} Stamotologiya");
                MainClass.JsonSerialize();
                return 1;
            }
            Console.Clear();
            Log.Information($"Reservation Failed. By {name} {surname} Non Empty Time.");
            return 1;
        }
    }

}

class Program
{
   

    static void Main()
    {
        MainClass.JsonDeSerialize();
        string format = "[{Timestamp:HH:mm:ss} {Level}] {Message} {Exception} {NewLine}";
        Log.Logger = new LoggerConfiguration()
            .WriteTo.Console(outputTemplate: format)
            .WriteTo.File("myLog.txt", outputTemplate: format)
            .CreateLogger();
        while (true)
        {
            try
            {
                Console.ForegroundColor = ConsoleColor.White;
                Console.BackgroundColor = ConsoleColor.Black;
                Console.WriteLine("Please enter your name: ");
                string name = Console.ReadLine();
                Console.WriteLine("Please enter your surname: ");
                string surname = Console.ReadLine();
                Console.WriteLine("Please enter your email: ");
                string email = Console.ReadLine();
                MailAddress mail = new MailAddress(email);
                Console.WriteLine("Please enter your phone: ");
                string phone = Console.ReadLine();
                if (phone.Length != 10 || phone.StartsWith("050") || phone.StartsWith("055") || phone.StartsWith("070") || phone.StartsWith("077") || phone.StartsWith("051") || phone.StartsWith("090"))
                    throw new Exception("Wrong Phone Number!");
                Console.WriteLine("Please enter day: ");
                string day = Console.ReadLine();
                Console.WriteLine("Please enter month: ");
                string month = Console.ReadLine();
                Console.WriteLine("Please enter year: ");
                string year = Console.ReadLine();
                Console.Clear();
                DateTime date = new DateTime(Int32.Parse(year), Int32.Parse(month), Int32.Parse(day));
                DateTime today = DateTime.UtcNow;
                if ((date - today).TotalDays > 0)
                {
                    if ((int)date.DayOfWeek != 6 && (int)date.DayOfWeek != 0)
                    {
                        Console.WriteLine("Welcome to the Hospital");
                        Console.WriteLine("Choose your reservation details");
                        Console.WriteLine(">> Pediatriya\n Travmatologiya\n Stamotologiya");
                        int arrow = 0;
                        while (true)
                        {
                            switch (Console.ReadKey().Key)
                            {
                                case ConsoleKey.UpArrow:

                                    if (arrow > 0)
                                        arrow--;
                                    Console.Clear();
                                    if (arrow == 0)
                                        Console.WriteLine(">> Pediatriya\n Travmatologiya\n Stamotologiya");
                                    else if (arrow == 1)
                                        Console.WriteLine(" Pediatriya\n>> Travmatologiya\n Stamotologiya");
                                    else
                                        Console.WriteLine(" Pediatriya\n Travmatologiya\n>> Stamotologiya");
                                    break;
                                case ConsoleKey.DownArrow:
                                    if (arrow + 1 < 3)
                                        arrow++;
                                    Console.Clear();
                                    if (arrow == 0)
                                        Console.WriteLine(">> Pediatriya\n Travmatologiya\n Stamotologiya");
                                    else if (arrow == 1)
                                        Console.WriteLine(" Pediatriya\n>> Travmatologiya\n Stamotologiya");
                                    else
                                        Console.WriteLine(" Pediatriya\n Travmatologiya\n>> Stamotologiya");
                                    break;
                                case ConsoleKey.Enter:
                                    Console.WriteLine(arrow);
                                    int value = MainClass.Run((arrow + 1).ToString(), name, surname, day, month, year);
                                    break;
                                default:
                                    Console.Clear();
                                    if (arrow == 0)
                                        Console.WriteLine(">> Pediatriya\n Travmatologiya\n Stamotologiya");
                                    else if (arrow == 1)
                                        Console.WriteLine(" Pediatriya\n>> Travmatologiya\n Stamotologiya");
                                    else
                                        Console.WriteLine(" Pediatriya\n Travmatologiya\n>> Stamotologiya");

                                    break;
                            };
                        }  
                    }
                    else
                    {
                        Console.Clear();
                        Log.Information($"Reservation Failed. By {name} {surname} Non Work Day!");
                    }
                }
                else
                {
                    Console.Clear();
                    Log.Information($"Reservation Failed. By {name} {surname} Wrong Date! Date: {date.ToString()}");
                }
            }
            catch (Exception e)
            {
                Console.Clear();
                Log.Error(e.Message, $"Exception Occurred");
            }
            
        }
    }
}
