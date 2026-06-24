#include<iostream>
#include<iomanip>  
#include<string>
using namespace std;

class Program
{
public:
	Program(int InHP, int InDamage)
	{
		hp = InHP;
		damage = InDamage;
	}
	void PrintScreen()
	{
		if (hp - damage <= 0)
		{
			cout << "KO";
		}
		else if ((hp - damage) * 5 <= hp)
		{
			cout << "Danger";
		}
		else
		{
			cout << "OK";
		}
	}

private:
	int hp;
	int damage;
};

int main()
{
	int InPutHP, InPutDamage;
	while (true)
	{
		cin >> InPutHP >> InPutDamage;
		if (InPutHP == -1) break;

		Program program(InPutHP, InPutDamage);
		program.PrintScreen();
		cout << endl; // o—Í‚²‚Æ‚É‰üs‚à“ü‚ê‚Ä‚¨‚­‚ÆŒ©‚â‚·‚¢
	}

	cout << "I—¹";
	return 0;
}