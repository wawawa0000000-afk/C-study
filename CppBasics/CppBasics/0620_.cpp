#include <iostream>
#include <string>

class Adventurer
{
public:
    Adventurer(std::string InName, int InHealth)
    {
        Name = InName; // this.Name ‚Å‚Í‚È‚­ Name ‚¾‚¯‚ÅOK
        Health = InHealth;
    }

public:
    void TakeDamage(int Amount)
    {
        Health -= Amount;
    }

public:
    void PrintStatus()
    {
        std::cout << Health << " " << Name << std::endl;
    }

private:
    std::string Name;
    int Health;
};

int main()
{
    Adventurer CallADV("aaa", 30);
    CallADV.PrintStatus();
    CallADV.TakeDamage(10);
    CallADV.PrintStatus();

    return 0;
}