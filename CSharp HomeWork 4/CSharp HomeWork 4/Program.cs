enum Gender { Male, Female };

class Animal {

    public string Nickname { get; set; }
    public int Age { get; set; }
    public Gender Gender { get; set; }
    public int Energy { get; set; }
    public float Price { get; set; }
    public int MealQuantity { get; set; }

    public Animal() {
        Nickname = default;
        Age = default;
        Gender = default;
        Energy = default;
        Price = default;
        MealQuantity = default;
    }

    public Animal(string nickname, int age, Gender gender, int energy, float price, int mealQuantity) {
        Nickname = nickname;
        Age = age;
        Gender = gender;
        Energy = energy;
        Price = price;
        MealQuantity = mealQuantity;
    }

    virtual public void Eat() { }

    virtual public void Sleep() { }

    virtual public void Play() { }

    virtual public void info() { Console.WriteLine($"Nickname: {Nickname}\nAge: {Age}\nGender: {Gender}\nEnergecy: {Energy}\nPrice: {Price}\nMeal Quantity: {MealQuantity}"); }
}

class Cat : Animal {

    int MaxEnergy;

    public Cat(string nickname, int age, Gender gender, int energy, float price, int mealQuantity)
        : base(nickname, age, gender, energy, price, mealQuantity) { MaxEnergy = energy; }
    public override void Eat() {
        if (base.MealQuantity < 100) {
            base.MealQuantity += 10;
        }
        else Console.WriteLine("Cat is not Hungry");
    }

    public override void Play() {
        base.Energy -= 50;
        if (base.Energy == 0 || base.Energy < 0) Console.WriteLine("Cat is Tired");
    }

    public override void Sleep() 
    { 
        if (base.Energy < 100)
        {
            base.Energy += 20;
        }else
        {
            Console.WriteLine("Cat is not Tired");
        }
    }
}

class Dog : Animal
{

    int MaxEnergy;

    public Dog(string nickname, int age, Gender gender, int energy, float price, int mealQuantity)
        : base(nickname, age, gender, energy, price, mealQuantity) { MaxEnergy = energy; }
    public override void Eat()
    {
        if (base.MealQuantity < 100)
        {
            base.MealQuantity += 10;
        }
        else Console.WriteLine("Cat is not Hungry");
    }

    public override void Play()
    {
        base.Energy -= 50;
        if (base.Energy == 0 || base.Energy < 0) Console.WriteLine("Cat is Tired");
    }

    public override void Sleep()
    {
        if (base.Energy < 100)
        {
            base.Energy += 20;
        }
        else
        {
            Console.WriteLine("Cat is not Tired");
        }
    }
}


class Program {
    static void Main()
    {
        Cat cat1 = new Cat("Mestan", 22, Gender.Male, 60, 249, 100);
        // Nickname ile silmeyi mentiqsiz bildim ona gore yazmadim eger itde ve pishikde eyni nickname varsa silecek...
    }

}