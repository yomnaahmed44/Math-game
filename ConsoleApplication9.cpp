#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include<iomanip>
#include<cstdlib>

enum leveldifficulty {easy=1, med=2, hard =3, mix=4};
enum optype{ add = 1, sub = 2, mul = 3, divison = 4, Mix = 5 };
int takenumber(string message) {
	cout <<message;
	int n;
	cin >> n;
	return n;
}
int randomnumber(int from, int to) {
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
int returnnumbers(leveldifficulty l) {
	switch (l) {
	case leveldifficulty::easy:
		return randomnumber(1, 10);
		break;
	case leveldifficulty::med:
		return randomnumber(10, 30);
		break;
	case leveldifficulty::hard:
		return randomnumber(30, 100);
		break;
	case leveldifficulty::mix:
		return randomnumber(1, 100);
		break;
	default:
		return randomnumber(1, 100);
		break;
}
}
char returnsign(optype o) {
	char c[5] = { '+','-','*','/','m'};
	switch (o) {
	case optype::add:
		return c[0];
		break;
	case optype::sub:
		return c[1];
		break;
	case optype::mul:
		return c[2];
		break;
	case optype::divison:
		return c[3];
		break;
	case optype::Mix:
		return c[randomnumber(0,3)];
		break;
	default:
		return c[randomnumber(0, 3)];
		break;
	}
}
string returnsignstring(optype o) {
	
	switch (o) {
	case optype::add:
		return "add";
		break;
	case optype::sub:
		return "sub";
		break;
	case optype::mul:
		return "mul";
		break;
	case optype::divison:
		return "div";
		break;
	case optype::Mix:
		return "mix";
		break;
	default:
		return "mix";
		break;
	}
}
int returncorrectans(char c, int x, int y) {
	switch (c) {
	case '+':
		return (x + y);
		break;
	case '-':
		return (x - y);
		break;
	case '/':
		return (x / y);
		break;
	case '*':
		return (x * y);
		break;
	default:
		return (x + y);
		break;
	}
}
bool correctanswer(int ans, int correctans) {
	if (ans == correctans)
		return true;
	else
		return false;
}
string returnlevelstring(leveldifficulty l) {
	switch (l) {
	case leveldifficulty::easy:
		return "Easy";
		break;
	case leveldifficulty::med:
		return "Med";
		break;
	case leveldifficulty::hard:
		return "Hard";
		break;
	case leveldifficulty::mix:
		return "Mix";
		break;
	default:
		return "Mix";
		break;
	}
}
void startgame() {
	int n = takenumber("How many questions do you want to answer?");
	int x = 1;
	int correct = 0;
	int wrong = 0;
	optype o;
	leveldifficulty l;
	int level = takenumber("Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?");
	int op = takenumber("Enter Questions Level [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?");
	while (n--) {
		
		 l = (leveldifficulty)level;
		 o = (optype)op;
		int num1 = returnnumbers(l);
		int num2 = returnnumbers(l);
		char opsign = returnsign(o);
		int correctans = returncorrectans(opsign, num1, num2);
		cout << "\n";
		cout << "Questions [" << x<<"/8]"<<endl;
		cout << "\n";
		cout << num1 << "\n" << num2 << " " << opsign<<endl;
		cout << "------------"<<endl;
		int ans;
		cin >> ans;
		if (correctanswer(ans, correctans)) {
			cout << "Correct answer :)"<<endl;
			system("color 2F");
			correct++;

		}
		else {
			cout << "Wrong answer :("<<endl;
			cout << "Correct answer is " << correctans<<endl;
			system("color 4F");
			cout << "\a";
			wrong++;
		}
		x++;

	}
	cout << "-----------------------------------------"<<endl;
	if(wrong>correct){
		cout << "\tFinal Result is fail :("<<endl;
		system("color 4F");
		cout << "\a";
	}
	else {
		cout << "\tFinal Result is Success :)" << endl;
		system("color 2F");
		
	}
		
	cout << "-----------------------------------------"<<endl;
	cout << "\n";
	cout << "number of questions: " << x<<endl;
	cout << "Questions Level: " << returnlevelstring(l)<<endl;
	cout << "Optype: " << returnsignstring(o) << endl;
	cout << "Number of right answers: " << correct<<endl;
	cout << "Number of wrong answers: " << wrong<<endl;
	cout << "Do  you want to play again? Y/N"<<endl;


}
int main()
{
	srand((unsigned)time(NULL));
	char y;
	do {
		startgame();
		cin >> y;
		system("cls");
		system("color 0F");
	} while (y == 'Y' || y == 'y');
}
