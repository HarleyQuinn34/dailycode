#include<iostream>
#include<Windows.h>
#include <ctime>
#include <string>
using namespace std;
int knockback(int D, int w, int p, double s, int b, double r);

//class definition
class smash
{
private:

	int lives;
	int damage;
    string name;

public:
	
	void initsmash(int x, int y, string z);
	void Printinfo();
	void takedamage( int num);
};

//function declaration



int main() {

	srand(time(NULL));
	while (1) {
		smash ness;
		ness.initsmash(4, 0, "ness");
		ness.Printinfo();
		ness.takedamage(knockback(30, 75, 20, 1.5, 20, 1.2)); //testing with food dropper
		ness.Printinfo();
	

		system("pause");
	}


}//end main

 //function declarations

	
int knockback(int D, int w, int p, double s, int b, double r) {

	int num;
	num = ((((7 * (D + 2) * (D + p)) / (w + 100) + 9) * 2 * s) + b) * r;
	cout << "damage calculated is " << num;
	return num;
}

void smash::takedamage(int num) {
	damage += num;
}
void smash::Printinfo() {
	cout << name;
	cout << "Ness's persentage is " << damage << "and lives are"<<lives<<endl;
}
void smash::initsmash(int x, int y, string z) {

	damage = 0;

	lives = 2;

}