using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_HomeWork_8
{
    internal class Credit
    {
        public readonly Guid Id;

        public Client MyClient { get; set; }

        public double Amount { get; set; }
        public int Percent { get; set; }
        public string Months { get; set; }

        public double Payment { get; set; }


        public Credit(Client myClient, double amount, int percent, string months)
        {
            Id = Guid.NewGuid();
            MyClient = myClient;
            Amount = amount;
            Percent = percent;
            Months = months;
            Payment = CalculatePayment();
        }

        public double CalculatePayment()
        {
            return Amount * Percent / 100;
        }

        public override string ToString() => $"Id: {Id}\nClient: {MyClient}\nAmount: {Amount}\nPercent: {Percent}\nMonths: {Months}\nPayment: {Payment}";

    }
}
