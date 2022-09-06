using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_HomeWork_8
{
    internal class Client : Human
    {
        public string LiveAddress { get; set; }
        public string WorkAddress { get; set; }
        public Credit Credit { get; set; }
        public Client(string name, string surname, int age, double salary, string work, string live, Credit credit) : base(name, surname, age, salary)
        {
            LiveAddress = live;
            WorkAddress = work;
            Credit = credit;
        }

        public override string ToString() => $"{base.ToString()}\nLive Address: {LiveAddress}\nWork Address: {WorkAddress}\nCredit: {Credit}";
    }
}
