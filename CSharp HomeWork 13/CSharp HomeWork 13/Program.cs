using CSharp_HomeWork_13;
using System.Linq;
using System.Xml.Linq;

static class Reservation
{

    static public Doctor[] Pediatria =
    {
        new Doctor(1,"Alice","Berry",1),
        new Doctor(2,"Alia","Carter",3),
        new Doctor(3,"Bella","Barnes",6)
    };
    static Doctor[] Travmatologiya =
    {
        new Doctor(1,"Aaliyah","Allen",7),
        new Doctor(2,"Alana","Atkins",18)
    };
    static Doctor[] Stamotologiya =
    {
        new Doctor(1,"Alexia","Brown",10),
        new Doctor(2,"Alicia","Brown",3),
        new Doctor(3,"Camren","Leon",12),
        new Doctor(4,"Lisandro","Lincoln",30)
    };

    static public int Run(string type, string name, string surname)
    {
        if (type == "1")
        {
            for (int i = 0; i < Pediatria.Length; i++)
            {
                Console.WriteLine($"{Pediatria[i]}\n");
            }
            int time = Int32.Parse(Console.ReadLine());
            for (int j = 0; j < Pediatria[time - 1].Worktime.Count; j++)
            {
                if (Pediatria[time - 1].Reserved.Contains(Pediatria[time - 1].Worktime[j]))
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
            if (!Pediatria[time - 1].Reserved.Contains(Pediatria[time - 1].Worktime[reservedtime - 1]))
            {
                Pediatria[time - 1].Reserved.Add(Pediatria[time - 1].Worktime[reservedtime - 1]);
                Console.Clear();
                Console.WriteLine($"Successfully Reserved By {name} {surname} at {Stamotologiya[time - 1].Worktime[reservedtime - 1]}");
                return 1;
            }
            Console.Clear();
            Console.WriteLine("Reservation Failed.");
            return 1;
        } 
        else if (type == "2")
        {
            for (int i = 0; i < Travmatologiya.Length; i++)
            {
                Console.WriteLine($"{Travmatologiya[i]}\n");
            }
            int time = Int32.Parse(Console.ReadLine());
            for (int j = 0; j < Travmatologiya[time - 1].Worktime.Count; j++)
            {
                if (Travmatologiya[time - 1].Reserved.Contains(Travmatologiya[time - 1].Worktime[j]))
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
            if (!Travmatologiya[time - 1].Reserved.Contains(Travmatologiya[time - 1].Worktime[reservedtime - 1]))
            {
                Travmatologiya[time - 1].Reserved.Add(Travmatologiya[time - 1].Worktime[reservedtime - 1]);
                Console.Clear();
                Console.WriteLine($"Successfully Reserved By {name} {surname} at {Stamotologiya[time - 1].Worktime[reservedtime - 1]}");
                return 1;
            }
            Console.Clear();
            Console.WriteLine("Reservation Failed.");
            return 1;
        } 
        else
        {
            for (int i = 0; i < Stamotologiya.Length; i++)
            {
                Console.WriteLine($"{Stamotologiya[i]}\n");
            }
            int time = Int32.Parse(Console.ReadLine());
            for (int j = 0; j < Stamotologiya[time - 1].Worktime.Count; j++)
            {
                if (Stamotologiya[time - 1].Reserved.Contains(Stamotologiya[time - 1].Worktime[j]))
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
            if (!Stamotologiya[time - 1].Reserved.Contains(Stamotologiya[time - 1].Worktime[reservedtime - 1]))
            {
                Stamotologiya[time - 1].Reserved.Add(Stamotologiya[time - 1].Worktime[reservedtime - 1]);
                Console.Clear();
                Console.WriteLine($"Successfully Reserved By {name} {surname} at {Stamotologiya[time - 1].Worktime[reservedtime - 1]}");
                return 1;
            }
            Console.Clear();
            Console.WriteLine("Reservation Failed.");
            return 1;
        }
    }

}

class Program
{
   

    static void Main()
    {
        while (true)
        {
            Console.ForegroundColor = ConsoleColor.White;
            Console.BackgroundColor = ConsoleColor.Black;
            Console.WriteLine("Please enter your name: ");
            string name = Console.ReadLine();
            Console.WriteLine("Please enter your surname: ");
            string surname = Console.ReadLine();
            Console.WriteLine("Please enter your email: ");
            string email = Console.ReadLine();
            Console.WriteLine("Please enter your phone: ");
            string phone = Console.ReadLine();
            Console.Clear();
            Console.WriteLine("Welcome to the Hospital");
            Console.WriteLine("Choose your reservation details");
            Console.WriteLine("1) Pediatriya\n2) Travmatologiya\n3) Stamotologiya\nMake Choice: ");
            string type = Console.ReadLine();
            if (type == "1" || type == "2" || type == "3")
            {
                int value = Reservation.Run(type, name, surname);
            } else
            {
                Console.WriteLine("Wrong Choice!");
                Console.Clear();
            }  
        }
    }
}