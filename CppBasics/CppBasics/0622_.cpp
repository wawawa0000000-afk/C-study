#include <iostream>
#include <string>
using namespace std;

class Adventurer
{
public:
    // コンストラクタ
    Adventurer(string InName, int InHealth)
    {
        Name = InName;
        Health = InHealth;
    }

    void TakeDamage(int Amount)
    {
        Health -= Amount;
    }

    void PrintStatus()
    {
        cout << "冒険者 " << Name << "（HP: " << Health << "）が現れた！" << endl;
    }

    void DamageStatus(int damage)
    {
        Health -= damage;
        cout << "冒険者" << Name << "は" << damage << "ダメージを食らった\nHP:" << Health << endl;
    }

private:
    string Name;
    int Health;
};

int main()
{
    // 1. 名前を保存するための変数を用意
    string InputName;

    cout << "冒険者の名前を入力してください: ";

    // 2. 【ここを穴埋め！】キーボードからの入力を InputName に受け取る
    cin >> InputName;

    // 3. 入力された名前を使って冒険者を作成（初期HPは 50 に設定）
    Adventurer Player(InputName, 50);

    // ステータスを表示
    Player.PrintStatus();

    Player.DamageStatus(10);

    return 0;
}