using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_HomeWork_13
{
    [Serializable]
    internal class User
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        private string? email;
        public string? Email
        {
            get { return email; }
            init
            {

                if (new System.Net.Mail.MailAddress(value).Address != value.Trim())
                    throw new ArgumentException("Invalid email");

                email = value;
            }
        }
        public string Phone { get; set; }

        public User(string name, string surname, string email, string phone)
        {
            Name = name;
            Surname = surname;
            Email = email;
            Phone = phone;
        }

        public override string ToString() => $"Name: {Name}\nSurname: {Surname}\nEmail: {Email}\nPhone: {Phone}";
    }
}
