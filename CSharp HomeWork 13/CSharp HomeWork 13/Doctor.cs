using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_HomeWork_13
{
    [Serializable]
    internal class Doctor
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public int Id { get; set; }
        public int Year { get; set; }
        public List<string> Reserved = new List<string>();
        public List<string> Worktime = new List<string>();
        public Doctor(int id, string name, string surname, int year)
        {
            Name = name;
            Surname = surname;
            Id = id;
            Year = year;
            Worktime.Add("9:00-11:00");
            Worktime.Add("12:00-14:00");
            Worktime.Add("15:00-17:00");
        }

        public override string ToString() => $"Id: {Id}\nName: {Name}\nSurname: {Surname}\nYear: {Year}"; 
    }
}
