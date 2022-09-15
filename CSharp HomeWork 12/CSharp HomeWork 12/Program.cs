using System;
using System.Diagnostics;
using System.Diagnostics.Metrics;
using System.Drawing;
using System.Runtime.Versioning;

static class Globals
{
    static public List<string> files = new();
}

[SupportedOSPlatform("windows")]
#nullable disable
static class Screenshot
{
    public static void TakeScreenShot()
    {
        Bitmap memoryImage;
        memoryImage = new Bitmap(1920, 1080);
        Size s = new Size(memoryImage.Width, memoryImage.Height);

        Graphics memoryGraphics = Graphics.FromImage(memoryImage);
        memoryGraphics.CopyFromScreen(0, 0, 0, 0, s);

        
        string fileName = string.Format($"C:\\Users\\{Environment.UserName}\\Desktop\\Screenshots\\" + @"\Screenshot" + "_" + DateTime.Now.ToString("(dd_MMMM_hh_mm_ss_tt)") + ".png");
        memoryImage.Save(fileName);
        Globals.files.Add(Path.GetFileName(fileName));
    }
}
[SupportedOSPlatform("windows")]
class Program
{
    static void Main()
    {
        Console.WriteLine("1) Take Screenshot\n2) Screenshots\n3) Delete Screenshot\n4) Open Screenshot\nMake Choice: ");
        string dir = $"C:\\Users\\{Environment.UserName}\\Desktop\\Screenshots";
        if (!Directory.Exists(dir))
            Directory.CreateDirectory(dir);
        
        foreach (var file in Directory.GetFiles($"C:\\Users\\{Environment.UserName}\\Desktop\\Screenshots"))
            Globals.files.Add(Path.GetFileName(file));

        while (true)
        {
            string option = Console.ReadLine();
            switch (option)
            {
                case "1":
                    Console.WriteLine("Press Enter");
                    string temp = Console.ReadLine();
                    Screenshot.TakeScreenShot();
                    Console.WriteLine("Screenshot has been saved!");
                    break;
                case "2":
                    int counter = 1;
                    foreach (var file in Directory.GetFiles($"C:\\Users\\{Environment.UserName}\\Desktop\\Screenshots"))
                    {
                        Console.WriteLine($"{counter}) {Path.GetFileName(file)}");
                        counter++;
                    }
                     break;
                case "3":
                    Console.WriteLine("Enter File Index: ");
                    int fileIndex = Int32.Parse(Console.ReadLine());
                    File.Delete(Globals.files[fileIndex - 1]);
                    Console.WriteLine("File Succesfully Deleted!");
                    break;
                case "4":
                    Console.WriteLine("Enter File Index: ");
                    int Index = Int32.Parse(Console.ReadLine());
                    System.Diagnostics.Process.Start(Globals.files[Index - 1]);
                    break;
                default:
                    Console.Clear();
                    Console.WriteLine("1) Take Screenshot\n2) Screenshots\n3) Delete Screenshot\n4) Open Screenshot\nMake Choice: ");
                    break;
                
            }
        }
    }
}