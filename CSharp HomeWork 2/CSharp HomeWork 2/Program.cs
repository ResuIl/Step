int Score = 0;
bool Flag = true;

string[,] Questions = new string[,] { 
    { "Sual 1?", "0Sual 1 Cavab1", "0Sual 1 Cavab2", "1Sual 1 Cavab3"},
    { "Sual 2?", "1Sual 2 Cavab1", "0Sual 2 Cavab2", "0Sual 2 Cavab3"},
    { "Sual 3?", "0Sual 3 Cavab1", "1Sual 3 Cavab2", "0Sual 3 Cavab3"},
    { "Sual 4?", "1Sual 4 Cavab1", "0Sual 4 Cavab2", "0Sual 4 Cavab3"},
    { "Sual 5?", "1Sual 5 Cavab1", "0Sual 5 Cavab2", "0Sual 5 Cavab3"},
    { "Sual 6?", "1Sual 6 Cavab1", "0Sual 6 Cavab2", "0Sual 6 Cavab3"},
    { "Sual 7?", "1Sual 7 Cavab1", "0Sual 7 Cavab2", "0Sual 7 Cavab3"},
    { "Sual 8?", "1Sual 8 Cavab1", "0Sual 8 Cavab2", "0Sual 8 Cavab3"},
    { "Sual 9?", "1Sual 9 Cavab1", "0Sual 9 Cavab2", "0Sual 9 Cavab3"},
    { "Sual 10?", "1Sual 10 Cavab1", "0Sual 0 Cavab2", "0Sual 10 Cavab3"},
};

for (int i = 0; i < 9; i++)
{
    int Counter = default;
    while (Flag)
    {
        if (i < 9)
        {
            Console.Clear();
            Console.WriteLine($"{Questions[i, 0]}");
            for (int j = 1; j < 4; j++)
            {
                if (j == Counter)
                    Console.ForegroundColor = ConsoleColor.Blue;
                string Main = Questions[i, j].Substring(1);
                Console.WriteLine($"{j}) {Main}");
                Console.ForegroundColor = ConsoleColor.White;
            }

            switch (Console.ReadKey().Key)
            {
                case ConsoleKey.UpArrow:
                    Console.Clear();
                    if (Counter != 0)
                        Counter--;
                    else
                        Counter = 3;
                    break;
                case ConsoleKey.DownArrow:
                    Console.Clear();
                    if (Counter != 3)
                        Counter++;
                    else
                        Counter = 0;
                    break;
                case ConsoleKey.Enter:
                    Console.Clear();
                    Console.WriteLine($"{i + 1}) {Questions[i, 0]}");
                    for (int y = 1; y < 4; y++)
                    {
                        if (y == Counter && Questions[i, y].Substring(0, 1) == "1")
                        {
                            Console.ForegroundColor = ConsoleColor.Green;
                            Score += 10;
                        }
                        else if (y == Counter)
                            Console.ForegroundColor = ConsoleColor.Red;

                        string Main = Questions[i, y].Substring(1);
                        Console.WriteLine($"{y}) {Main}");
                        Console.ForegroundColor = ConsoleColor.White;
                    }
                    i++;
                    break;

            }
        }

        if (i == 9)
        {
            Flag = false;
            Console.WriteLine($"Total Score: {Score}");
        }
      
    }
}