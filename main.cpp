#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

struct ThisMove {
	int moveCount;
	int position;
	char mark;
};

class Move {

	int moveCount;

public:
	vector<ThisMove> moves{ { 0, 0, '1' }, { 1, 0, '2' }, { 2, 0, '3' }, { 3, 0, '4' }, { 4, 0, '5' } };
	Move() : moveCount(-1) {}

	bool InputMove(int _position, char _mark) {
		moveCount++;
		moves[moveCount % 5] = { moveCount % 5, _position ,  _mark };
		return 1;
	}

	bool MoveExistance(int pos) {
		for (auto el : moves) {
			if (el.position == pos)
				return 1;
		}
		return 0;
	}

};

class tictactoe {

	int player = 1;
	char mark, choice;
	Move moves;
	vector<char> square = { '1','2','3','4','5','6','7','8','9' };
	const vector<char> defaultsquare = { '1','2','3','4','5','6','7','8','9' };
	string P1Name = "P1(X)", P2Name = "P2(O)";

public:

	tictactoe() : choice(' '), mark(' ') {}

	tictactoe(string p1name, string p2name) {
		SetPlayer1Name(p1name);
		SetPlayer2Name(p2name);
	}

	bool SetPlayer1Name(string p1name) {
		P1Name = p1name;
		return 1;
	}

	bool SetPlayer2Name(string p2name) {
		P2Name = p2name;
		return 1;
	}

	string GetPlayer1Name() {
		return P1Name;
	}

	string GetPlayer2Name() {
		return P2Name;
	}

	void newMove(int position, char mark) {
		if (verify(position, mark)) {
			moves.InputMove(position, mark);
			Erase();
		}
	}
	
	void Erase() {

		for (int i = 0; i < 9; i++) {
			if (moves.MoveExistance(i))
				square[i] = moves.moves[(i)%5].mark;
			else
				square[i] = (char)i + 49;
		}
		
	}

	bool checkwin() {
		if (square[0] == square[1] && square[1] == square[2])
			return 1;
		else if (square[3] == square[4] && square[4] == square[5])
			return 1;
		else if (square[6] == square[7] && square[7] == square[8])
			return 1;
		else if (square[0] == square[3] && square[3] == square[6])
			return 1;
		else if (square[1] == square[4] && square[4] == square[7])
			return 1;
		else if (square[2] == square[5] && square[5] == square[8])
			return 1;
		else if (square[0] == square[4] && square[4] == square[8])
			return 1;
		else if (square[2] == square[4] && square[4] == square[6])
			return 1;
		else
			return 0;
	}

	bool verify(int position, char mark) {

		if (square[position] - 49 == position) {
			square[position] = mark;
			return 1;
		}
		else {
			throw "Wrong move";
			return 0;
		}

	}

	void Show() {
		system("cls");

		cout << GetPlayer1Name() << "  vs  " << GetPlayer2Name() << endl << endl;

		cout << "     |     |     " << endl;
		cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;

		cout << "     |     |     " << endl << endl;
	}

	void play() {

		//cout << "input name of player 1: ";
		//cin >> P1Name;

		//cout << "input name of player 2: ";
		//cin >> P2Name;

		tictactoe ttt;

		do {
			ttt.Show();
			player = (player % 2) ? 1 : 2;

			cout << "Player " << ((player == 1) ? ttt.GetPlayer1Name() : ttt.GetPlayer2Name()) << ", enter a number:  ";
			cin >> choice;

			mark = (player == 1) ? 'X' : 'O';

			ttt.newMove((int)choice - 49, mark);

			ttt.checkwin();

			player++;
		} while (!ttt.checkwin());
		ttt.Show();
		if (ttt.checkwin())
			cout << "Player " << (--player == 1 ? ttt.GetPlayer1Name() : ttt.GetPlayer2Name()) << " wins ";
	}

};

int main() {

tictactoe ttt;
ttt.play();

//system("pause");
return 0;
}