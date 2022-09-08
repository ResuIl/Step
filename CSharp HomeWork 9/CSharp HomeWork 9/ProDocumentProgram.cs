using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_HomeWork_9
{
    internal class ProDocumentProgram : DocumentProgram
    {
        public sealed override void EditDocument() => base.EditDocument();
        public override void SaveDocument() => Console.WriteLine("Document Saved in doc format, for pdf format buy Expert packet");
    }
}
