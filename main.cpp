#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

enum enGet { paper = 1, stone = 2, scissors = 3 };
enum enWinner { Player1 = 1, Player2 = 2, same = 0 };

void Header() {
	cout << "\n\t\t\tWELCOME TO MY GAME\t\t\t\n";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n\t\tPaper = 1\tStone = 2\tScissors = 3\t\n";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}

int GetRound() {
	int round = 0;
	do {
		cout << "How Many Rounds? : ";
		cin >> round;
	} while (round <= 0);
	return round;
}

int Random(int from = 1, int to = 3) {
	return rand() % (to - from + 1) + from;
}

enGet GetPlayer1() {
	int choice;
	do {
		cout << "Please Enter Your Choice: Paper [1] | Stone [2] | Scissors [3] : ";
		cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3);
	return enGet(choice);
}

enGet GetPlayer2() {
	return enGet(Random());
}

void getPlayers(enGet& Player1, enGet& Player2) {
	Player1 = GetPlayer1();
	Player2 = GetPlayer2();
}

void printVS(enGet& Player1, enGet& Player2) {
	string p1, p2;
	if (Player1 == paper) p1 = "Paper";
	else if (Player1 == stone) p1 = "Stone";
	else if (Player1 == scissors) p1 = "Scissors";

	if (Player2 == paper) p2 = "Paper";
	else if (Player2 == stone) p2 = "Stone";
	else if (Player2 == scissors) p2 = "Scissors";

	cout << "\nPlayer 1 Chose: " << p1 << "\nPlayer 2 Chose: " << p2 << endl;
}

enWinner CheckWinner(enGet& Player1, enGet& Player2) {
	if (Player1 == Player2) return enWinner::same;
	else if (Player1 == paper && Player2 == stone) return enWinner::Player1;
	else if (Player1 == scissors && Player2 == paper) return enWinner::Player1;
	else if (Player1 == stone && Player2 == scissors) return enWinner::Player1;
	else return enWinner::Player2;
}

void print(int round, enGet& Player1, enGet& Player2) {
	enWinner w;
	int countP1 = 0, countP2 = 0, draw = 0;
	for (int i = 1; i <= round; i++) {
		cout << "---------------------------[Round " << i << " ]---------------------------\n" << endl;
		getPlayers(Player1, Player2);
		printVS(Player1, Player2);
		w = CheckWinner(Player1, Player2);
		if (w == enWinner::Player1) {
			countP1++;
			cout << "Player One Wins.\n\n";
			system("color A");
		}
		else if (w == enWinner::Player2) {
			countP2++;
			cout << "\aPlayer Two Wins.\n\n";
			system("color C");
		}
		else {
			cout << "It's a Draw.\n\n";
			draw++;
			system("color E");
		}
		cout << endl;
	}

	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n\t\t\t    +++ GAME OVER +++\t\t\t\n";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t  Player One Won Times: " << countP1 << "\n\t\t\t  Player Two Won Times: " << countP2 << "\n\t\t\t  Draw Times: " << draw << endl;

	if (countP1 > countP2) cout << "\t\t\t  Player One is the Winner.\n";
	else if (countP1 < countP2) cout << "\t\t\t  Player Two is the Winner.\n";
	else cout << "\t\t\t  It's a Draw.\n";
}
void startgame()
{
	Header();
	int round = 0;
	enGet p1, p2;
	bool choose = false;
	do {
		print(round = GetRound(), p1, p2);
		cout << "\n\t\tDo You Want to Play Again? Yes :[1] , No :[0]? ";
		cin >> choose;
		system("cls");
	} while (choose);
}
int main() {

	srand((unsigned)time(NULL));
	startgame();
}
