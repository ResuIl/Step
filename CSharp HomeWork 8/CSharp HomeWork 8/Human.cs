using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_HomeWork_8
{
    internal class Human
    {
        public readonly Guid Id;
        public string Name { get; set; }
        public string Surname { get; set; }
        public int Age { get; set; }
        public double Salary { get; set; }
        public Human(string name, string surname, int age, double salary)
        {
            Id = Guid.NewGuid();
            Name = name;
            Surname = surname;
            Age = age;
            Salary = salary;
        }

        public override string ToString() => $"Id: {Id}\nName: {Name}\nSurname: {Surname}\nAge: {Age}\nSalary: {Salary}";
    }
}
