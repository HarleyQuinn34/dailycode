#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main() {
	srand(time(NULL));
	int input;
	string key[20] = { "big", "fat", "giggantic", "great", "high", "huge", "immense", "large", "little", "lil", "mammoth", "massive", "mini", "petite", "short", "skinny", "smart", "tall", "tiny", "immortal" };
	string key2[20] = { "dill", "doggo", "dual pump", "greasy", "tower", "mire", "store", "lump", "chub", "PP", "steve", "dong", "lad", "mate", "dung", "scar", "blorgus", "boi", "booti", "trash" };
	
	while (1) {
		int k = rand() % 20;
		int k2 = rand() % 20;
		cout << "Press (y) for a rapper name" << endl;
		cin >> input;
		cout << key[k] << " " << key2[k2] << endl;
		system("pause");
	}









}