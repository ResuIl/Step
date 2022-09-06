using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_HomeWork_8
{
    internal class Operation
    {
        public readonly Guid Id;
        public string ProcessName { get; set; }
        public readonly DateTime DateTime;

        public Operation(string processName)
        {
            Id = Guid.NewGuid();
            ProcessName = processName;
            DateTime = DateTime.Now;
        }

        public override string ToString() => $"Id: {Id}\nProcess Name: {ProcessName}\nDate Time: {DateTime}";
    }
}
