using System;
using System.Net.Mail;
using System.Net;
class User
{
    private string UserName { get; set; }
    private string Password { get; set; }
    private string Email { get; set; }
    private bool IsAdmin { get; set; }

    public User(string _UserName, string _Password,string _Email, bool _IsAdmin)
    {
        UserName = _UserName;
        Password = _Password;
        Email = _Email;
        IsAdmin = _IsAdmin;
    }
    public string GetUsername() { return UserName; }
    public string GetPassword() { return Password; }
    public string GetMail() { return Email; }
    public bool IsAdminn() { return IsAdmin; }
}

class Post
{
    private int Id { get; set; }
    private string Content { get; set; }
    private DateTime DateTime { get; set; }
    private int LikeCount { get; set; }
    private int ViewCount { get; set; }
    private User PostAuthor { get; set; }

    public Post(string content, DateTime dateTime, User user)
    {
        Id = Program._Id++;
        Content = content;
        DateTime = dateTime;
        LikeCount = 0;
        ViewCount = 0;
        PostAuthor = user;
    }
    public int GetId() { return Id; }
    public void AddLike() { LikeCount++; }
    public void RemoveLike() { LikeCount--; }
    public void EditContent(string cont) {  Content = cont; }
    public string GetContent() { return Content; }
    public static Post operator ++(Post a)
    {
        a.ViewCount++;
        return a;
    }
    public static Post operator --(Post a)
    {
        a.ViewCount++;
        return a;
    }
    public override string ToString() { return "ID: " + Id + "\n\tContent: " + Content + "\n\tView Count: " + ViewCount + "\n\tLike Count: " + LikeCount + "\n\tAuthor: " + PostAuthor.GetUsername() + "\n\tDate: " + DateTime.ToString(); }
}

class Program
{
    public static int _Id = 0;
    static void Main()
    {
        List<User> users = new();
        users.Add(new User("resul", "resul123", "resul@gmail.com", false));
        users.Add(new User("islam", "islam123", "islam@gmail.com", true));

        List<Post> posts = new List<Post>();
        Post[] AllPosts =
        {
            new Post("First Post", DateTime.Now, users[0]),
            new Post("Second Post", DateTime.Now, users[1])
        };

        posts.AddRange(AllPosts);

        Console.WriteLine("1) Login\n2) Register\nMake Choice: ");
        while (true)
        {
            string menu = Console.ReadLine();
            if (menu == "1")
            {
                int LoginFlag = -1;
                Console.WriteLine("Enter Username: ");
                string TempUsername = Console.ReadLine();
                Console.WriteLine("Enter Password: ");
                string TempPassword = Console.ReadLine();
                for (int i = 0; i < users.Count; i++)
                {
                    if (users[i].GetUsername() == TempUsername)
                    {
                        if (users[i].GetPassword() == TempPassword)
                        {
                            Console.WriteLine("Logined Redirecting...");
                            System.Threading.Thread.Sleep(2000);
                            Console.Clear();
                            LoginFlag = i;
                            break;
                        }
                    }
                }

                if (LoginFlag != -1)
                {

                    if (users[LoginFlag].IsAdminn())
                    {
                        Console.WriteLine("1) Show Posts\n2) Add Post\n3) Edit Post\n4) Logout");
                    } 
                    else
                    {
                        Console.WriteLine("1) Show Posts\n2) Look Post\n3) Like Post\n4) Logout");
                    }
                    
                    while (users[LoginFlag].IsAdminn()) // Admin
                    {
                        Console.WriteLine("Make Choice: ");
                        string choicse = Console.ReadLine();
                        if (choicse == "1")
                        {
                            foreach (Post post in posts)
                            {
                                Console.WriteLine(post);
                            }
                        }
                        else if (choicse == "2")
                        {
                            Console.WriteLine("Enter Content: ");
                            string Content = Console.ReadLine();
                            posts.Add(new Post(Content, DateTime.Now, users[LoginFlag]));
                            Console.WriteLine("Successfully Posted!");

                        }
                        else if (choicse == "3")
                        {
                            try
                            {
                                Console.WriteLine("Enter Post ID: ");
                                int postId = Int32.Parse(Console.ReadLine());
                                Console.WriteLine("Enter Content: ");
                                string conte = Console.ReadLine();
                                posts[postId].EditContent(conte);
                                Console.WriteLine("Successfully Edited.");
                            }
                            catch (Exception)
                            {
                                Console.WriteLine("Post Not Found!");
                            }
                        }
                        else if (choicse == "4")
                        {
                            LoginFlag = -1;
                            Console.Clear();
                            Console.WriteLine("1) Login\n2) Register\nMake Choice: ");
                            break;
                        }
                        else
                        {
                            Console.Clear();
                            Console.WriteLine("1) Show Posts\n2) Add Post\n3) Edit Post\n4) Logout");
                        }
                    }

                    if (LoginFlag != -1)
                    {
                        while (!users[LoginFlag].IsAdminn()) // User
                        {
                            Console.WriteLine("Make Choice: ");
                            string choicse = Console.ReadLine();
                            if (choicse == "1")
                            {
                                foreach (Post post in posts)
                                {
                                    Console.WriteLine(post);
                                }
                            }
                            else if (choicse == "2")
                            {
                                try
                                {
                                    Console.WriteLine("Enter Post ID: ");
                                    int postIndex = Int32.Parse(Console.ReadLine());
                                    posts[postIndex]++;
                                    Console.WriteLine(posts[postIndex]);
                                }
                                catch (Exception)
                                {
                                    Console.WriteLine("Post Not Found!");
                                }
                            }
                            else if (choicse == "3")
                            {
                                try
                                {
                                    Console.WriteLine("Enter Post ID: ");
                                    int postIndex = Int32.Parse(Console.ReadLine());
                                    posts[postIndex]++;
                                    posts[postIndex].AddLike();
                                    Console.WriteLine("Post Liked!");
                                }
                                catch (Exception)
                                {
                                    Console.WriteLine("Post Not Found!");
                                }
                            }
                            else if (choicse == "4")
                            {
                                LoginFlag = -1;
                                Console.Clear();
                                Console.WriteLine("1) Login\n2) Register\nMake Choice: ");
                                break;
                            }
                            else
                            {
                                Console.Clear();
                                Console.WriteLine("1) Show Posts\n2) Look Post\n3) Like Post\n4) Logout");
                            }
                        }
                    }
                } else
                {
                    Console.WriteLine("Incorrect Username Or Password");
                    return;
                }
            }
            else if (menu == "2")
            {
                Console.WriteLine("Enter Username: ");
                string TempUsername = Console.ReadLine();
                Console.WriteLine("Enter Mail: ");
                string TempMail = Console.ReadLine();
                Console.WriteLine("Enter Password: ");
                string TempPassword = Console.ReadLine();
                foreach (User u in users)
                {
                    if (u.GetUsername() == TempUsername || u.GetMail() == TempMail)
                    {
                        Console.WriteLine("Username or Mail Is Registerd.");
                        return;
                    }
                }

                users.Add(new User(TempUsername, TempPassword, TempMail, false));
                Console.WriteLine("Successfully Registered! Please Wait...");
                System.Threading.Thread.Sleep(2000);
                Console.Clear();
                Console.WriteLine("1) Login\n2) Register\nMake Choice: ");
            }
            else
            {
                Console.Clear();
                Console.WriteLine("1) Login\n2) Register\nMake Choice: ");
            }

        }
    }
}