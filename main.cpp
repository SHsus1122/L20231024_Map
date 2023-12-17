#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


// ���� ��α� : https://coding-factory.tistory.com/690
// ��ǥ �̵��� �Լ�
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void gotoxyPrint(int y)
{
	COORD Pos;
	Pos.X = 0;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


int main() {

	int MapXSize = 0;
	int MapYSize = 0;

	cout << "�� ����� �Է����ּ���. ex) 10 5" << endl;
	while (true) {
		cin >> MapXSize >> MapYSize;
		if (MapXSize < 3 || MapYSize < 3)
		{
			cout << "�� ����� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���.\n�ּ� ������� 3 X 3 �Դϴ�.";
			continue;
		}
		else
		{
			MapXSize == 3 ? 3 : MapXSize;
			MapYSize == 3 ? 3 : MapYSize;
			break;
		}
	}


	int PlayerX = MapXSize / 2;
	int PlayerY = MapYSize / 2;
	system("cls");

	char PlayerShape = 'P';
	bool bIsRunning = true;

	/*for (int i = 0; i <= MapXSize; i++)
	{
		cout << '*';
	}
	cout << endl;
	for (int i = 0; i < MapYSize; i++)
	{
		for (int j = 0; j <= MapXSize; j++)
		{
			if (j == 0 || j == MapXSize)
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
	for (int i = 0; i <= MapXSize; i++)
	{
		cout << '*';
	}*/
	for (int i = 0; i < MapYSize; i++) {
		for (int j = 0; j < MapXSize; j++) {
			if (i == 0 || i == MapYSize - 1 || j == 0 || j == MapXSize - 1) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		if (i != MapYSize) cout << endl;
	}


	while (bIsRunning)
	{
		//char Key = _getch();
		int Key = _getch();

		int PreviousX = PlayerX;
		int PreviousY = PlayerY;
		string PrintWay[4] = {"[ �� ]", "[ �� ]", "[ �� ]", "[ �� ]"};
		string Wall = "���̻� �̵��� �� �����ϴ�.";

		//system("cls"); // cmd â ����� dos ��ɾ� �̴� �߰��ϰ� �Ǹ� ��ŷ ���� �� �ֽ��ϴ�.

		gotoxyPrint(MapYSize + 2);
		if (Key == 'a' || Key == 'A')		// ����
		{	
			if (PlayerX <= 1)
			{
				cout << Wall;
			}
			else
			{
				cout << PrintWay[0] << string(Wall.length(), ' ');
				PlayerX--;
			}
		}
		else if (Key == 'w' || Key == 'W')	// ����
		{
			if (PlayerY <= 1)
			{
				cout << Wall;
			}
			else
			{
				cout << PrintWay[1] << string(Wall.length(), ' ');
				PlayerY--;
			}
		}
		else if (Key == 's' || Key == 'S')	// �Ʒ���
		{
			if (PlayerY >= MapYSize - 2)
			{
				cout << Wall << endl;
			}
			else
			{
				cout << PrintWay[2] << string(Wall.length(), ' ');
				PlayerY++;
			}
		}
		else if (Key == 'd' || Key == 'D')	// ������
		{
			if (PlayerX >= MapXSize - 2)
			{
				cout << Wall;
			}
			else
			{
				cout << PrintWay[3] << string(Wall.length(), ' ');
				PlayerX++;
			}
		}
		else if (Key == 'q' || Key == 'Q')
		{
			cout << "����" << endl;
			bIsRunning = false;
		}

		// ���� ��ǥ�� ��ġ�� "P"�� �����ݴϴ�.
		gotoxy(PreviousX, PreviousY);
		cout << " ";

		// ���� �̵��� ��ǥ�� ��ġ���� "P" �� ����մϴ�.
		gotoxy(PlayerX, PlayerY);
		cout << PlayerShape;

	}

	return 0;
}