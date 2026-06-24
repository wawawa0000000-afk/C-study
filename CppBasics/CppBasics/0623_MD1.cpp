#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Program
{
public:
	Program(int Inscore, float Inaccuracy, string InplayerName)
	{
		score = Inscore;
		accuracy = Inaccuracy;
		playerName = InplayerName;
	}
	void PrintScreen()
	{
		cout << fixed << setprecision(2);
		cout << "Player: " << playerName << "\n" << "Score:" << score << "(Accuracy: " << accuracy << "%)" << endl;
	}
private:
	int score;
	float accuracy;
	string playerName;
};

int main()
{
	int InPutScore;
	float InPutaccuracy;
	string InPutplayerName;
	
	cin >> InPutplayerName >> InPutScore >> InPutaccuracy;

	Program program (InPutScore,InPutaccuracy,InPutplayerName);
	program.PrintScreen();
	
	return 0;
}