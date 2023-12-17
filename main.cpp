#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


// 참고 블로그 : https://coding-factory.tistory.com/690
// 좌표 이동용 함수
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

	cout << "맵 사이즈를 입력해주세요. ex) 10 5" << endl;
	while (true) {
		cin >> MapXSize >> MapYSize;
		if (MapXSize < 3 || MapYSize < 3)
		{
			cout << "맵 사이즈가 너무 작습니다. 다시 입력해주세요.\n최소 사이즈는 3 X 3 입니다.";
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
		string PrintWay[4] = {"[ ← ]", "[ ↑ ]", "[ ↓ ]", "[ → ]"};
		string Wall = "더이상 이동할 수 없습니다.";

		//system("cls"); // cmd 창 지우는 dos 명령어 이는 추가하게 되면 해킹 당할 수 있습니다.

		gotoxyPrint(MapYSize + 2);
		if (Key == 'a' || Key == 'A')		// 왼쪽
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
		else if (Key == 'w' || Key == 'W')	// 위쪽
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
		else if (Key == 's' || Key == 'S')	// 아래쪽
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
		else if (Key == 'd' || Key == 'D')	// 오른쪽
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
			cout << "종료" << endl;
			bIsRunning = false;
		}

		// 이전 좌표의 위치인 "P"를 지워줍니다.
		gotoxy(PreviousX, PreviousY);
		cout << " ";

		// 현재 이동한 좌표의 위치에서 "P" 를 출력합니다.
		gotoxy(PlayerX, PlayerY);
		cout << PlayerShape;

	}

	return 0;
}