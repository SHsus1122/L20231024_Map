#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
	//// 랜덤한 시간
	//srand(time(nullptr));

	//rand(); // 0 ~ 32767 숫자중 랜덤
	//bool Decision = ((rand() % 2) == 0);

	// 참이냐 거짓이냐에 따라 실행하는 조건문
	// ture 일 경우 짜장, false 의 경우에는 짬뽕

	// for (;;) {} 무한한 반복문

	int PlayerX = 1;
	int PlayerY = 1;
	char PlayerShape = 'P';
	bool bIsRunning = true;
	while (bIsRunning)
	{
		//char Key = _getch();
		int Key = _getch();

		system("cls"); // cmd 창 지우는 dos 명령어 이는 추가하게 되면 해킹 당할 수 있습니다.

		if (Key == 'a' || Key == 'A')
		{
			cout << "왼쪽" << endl;
			PlayerX--;
		}
		else if (Key == 'w' || Key == 'W')
		{
			cout << "위로" << endl;
			PlayerY--;
		}
		else if (Key == 's' || Key == 'S')
		{
			cout << "아래로" << endl;
			PlayerY++;
		}
		else if (Key == 'd' || Key == 'D')
		{
			cout << "오른쪽" << endl;
			PlayerX++;
		}
		else if (Key == 'q' || Key == 'Q')
		{
			cout << "종료" << endl;
			bIsRunning = false;
		}

		cout << PlayerX << ", " << PlayerY << endl;

		// 참고 블로그 : https://coding-factory.tistory.com/690
		//x, y 좌표 설정
		COORD pos = { PlayerX, PlayerY };
		//커서 이동
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << PlayerShape;

	}



	return 0;
}