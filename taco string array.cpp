#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main() {
	
	string input;
	string food[5];
	bool hasTaco = false;

		
		cout << "What is your favorite food?" << endl;
		
		for (int i = 0; i < 5; i++) {
			cin >> input;
			food[i] = input;
		}


		for (int i = 0; i < 5; i++) {
			if (food[i] == "taco" || food[i] == "tacos")
				hasTaco = true;
			
		}

		if (hasTaco == true)
			cout << "TACO!" << endl;
		else
			cout << "yuck! no tacos!" << endl;

		

		
		system("pause");
	









}