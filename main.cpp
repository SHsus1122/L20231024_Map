#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
	//// ������ �ð�
	//srand(time(nullptr));

	//rand(); // 0 ~ 32767 ������ ����
	//bool Decision = ((rand() % 2) == 0);

	// ���̳� �����̳Ŀ� ���� �����ϴ� ���ǹ�
	// ture �� ��� ¥��, false �� ��쿡�� «��

	// for (;;) {} ������ �ݺ���

	int PlayerX = 1;
	int PlayerY = 1;
	char PlayerShape = 'P';
	bool bIsRunning = true;
	while (bIsRunning)
	{
		//char Key = _getch();
		int Key = _getch();

		system("cls"); // cmd â ����� dos ��ɾ� �̴� �߰��ϰ� �Ǹ� ��ŷ ���� �� �ֽ��ϴ�.

		if (Key == 'a' || Key == 'A')
		{
			cout << "����" << endl;
			PlayerX--;
		}
		else if (Key == 'w' || Key == 'W')
		{
			cout << "����" << endl;
			PlayerY--;
		}
		else if (Key == 's' || Key == 'S')
		{
			cout << "�Ʒ���" << endl;
			PlayerY++;
		}
		else if (Key == 'd' || Key == 'D')
		{
			cout << "������" << endl;
			PlayerX++;
		}
		else if (Key == 'q' || Key == 'Q')
		{
			cout << "����" << endl;
			bIsRunning = false;
		}

		cout << PlayerX << ", " << PlayerY << endl;

		// ���� ��α� : https://coding-factory.tistory.com/690
		//x, y ��ǥ ����
		COORD pos = { PlayerX, PlayerY };
		//Ŀ�� �̵�
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << PlayerShape;

	}



	return 0;
}