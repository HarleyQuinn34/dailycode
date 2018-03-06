#include <allegro5/allegro.h>
#include <iostream>
#include<Windows.h>
#include <ctime>
using namespace std;
//function declaration
char foodDrop(char location);



//class definition
class pk {
private:
	int health;

public:
	void eat(char c);
	void initpk(int num);
	void printinfo();
};
int main() {
	srand(time(NULL));
	pk kirby;
	kirby.initpk(100);
	while (1) {

		kirby.printinfo();
		//kirby.eat(fooddrop('d'));
		kirby.eat(foodDrop('d'));
		kirby.printinfo();

		system("pause");
	}
}
char foodDrop(char location) {

	int num = rand() % 100 + 1;

	if (location == 'f') {
		if (num <= 50) {
			cout << "you got a berry!" << endl;
			return 'b';
		}
		else {
			cout << "you got a mushroom!" << endl;
			return 'm';

		}
	}
	else if (location == 'd') {
		if (num <= 20) {
			cout << "You got a berry!" << endl;
			return 'b';
		}
		else if (num <= 60) {
			cout << "You got a fruit!" << endl;
			return 'f';
		}
		else if (num < 100) {
			cout << "You found some cheese?" << endl;
			return 'c';
		}
	}


	else
		cout << "invalid location" << endl;

}

//function definitions
void pk::eat(char food) {
	if (food == 'b')
		health += 3;
	if (food == 'd')
		health += 5;
	if (food == 'm')
		health += 2;
	if (food == 'f')
		health += 1;

}

void pk::initpk(int num) {
	health = num;

}
void pk::printinfo() {
	cout << "Your " << health << endl;

}
