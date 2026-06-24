#include <iostream>
#include <string>
using namespace std;

class Program
{
public:
	Program(int Inattack, int Indefense, bool InisCritical)
	{
		attack = Inattack;
		defense = Indefense;
		isCritical = InisCritical;
	}
private:
	int attack;
	int defense;
	bool isCritical;
};

int calculateDamage(int attack, int defense, bool isCritical)
{
	int damage = attack - defense / 2;
	if (isCritical)
	{
		damage = static_cast<int>(damage * 1.5);
	}
	if (damage < 0)
	{
		damage = 1;
	}
	return damage;
}

int main()
{
	int testCount;
	cout << "ƒeƒXƒg‚·‚éŒ”‚ð“ü—Í: ";
	cin >> testCount;

	for (int i = 0; i < testCount; i++)
	{
		int inputAttack, inputDefense;
		bool inputIsCritical;
		cin >> inputAttack >> inputDefense >> inputIsCritical;

		int damage = calculateDamage(inputAttack, inputDefense, inputIsCritical);
		cout << "Damage:" << damage << endl;
	}
	return 0;
}