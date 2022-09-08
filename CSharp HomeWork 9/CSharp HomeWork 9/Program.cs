using CSharp_HomeWork_9;

class Program
{
    static void Main()
    {
        Console.WriteLine("Document Editor Program\n1) Basic\n2) Pro\n3) Expert\nMake Choice: ");
        while (true)
        {
            string option = Console.ReadLine();
            if (option == "1")
            {
                DocumentProgram basic = new DocumentProgram();
                basic.OpenDocument();
                basic.EditDocument();
                basic.SaveDocument();
            }
            else if (option == "2")
            {
                ProDocumentProgram pro = new ProDocumentProgram();
                pro.OpenDocument();
                pro.EditDocument();
                pro.SaveDocument();
            }
            else if (option == "3")
            {
                ExpertDocument expert = new ExpertDocument();
                expert.OpenDocument();
                expert.EditDocument();
                expert.SaveDocument();
            }
            else
            {
                Console.Clear();
                Console.WriteLine("Document Editor Program\n1) Basic\n2) Pro\n3) Expert\nMake Choice: ");
            }
        }
    }
}