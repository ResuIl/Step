using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_HomeWork_8
{
    internal class CEO : Human, IControl, IOrganizer, IMeet, IDecrease
    {
        public string Position { get; set; }
        public CEO(string name, string surname, int age, double salary, string position) : base(name, surname, age, salary)
        {
            Position = position;
        }

        public void Control() => Console.WriteLine("CEO Control");

        public void DecreasePersentage() => Console.WriteLine("CEO DecreasePersentage");

        public void MakeMeeting() => Console.WriteLine("CEO MakeMeeting");

        public void Organize() => Console.WriteLine("CEO Organize");

        public override string ToString() => $"{base.ToString()}\nPosition: {Position}";
    }
}
