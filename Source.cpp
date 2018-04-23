#include <iostream>
#include <vector>
#include<algorithm>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string A = "Alpha";
	string B = "Bravo";
	string C = "Charlie";
	string D = "Delta";
	string E = "Echo";
	string F = "Foxtrot";
	string G = "Golf";
	string H = "Hotel";
	string I = "India";
	string J = "Juliet";
	string K = "Kilo";
	string L = "Lima";
	string M = "Mike";
	string N = "November";
	string O = "Oscar";
	string P = "Papa";
	string Q = "Quebec";
	string R = "Romeo";
	string S = "Sierra";
	string T = "Tango";
	string U = "Uniform";
	string V = "Victor";
	string W = "Whiskey";
	string X = "X-ray";
	string Y = "Yankee";
	string Z = "Zulu";

	//1. set up vector
	char mili;
	vector<char> mili2;
	vector<char>::iterator iter1;
	vector<string>::iterator iter2;
	vector<string>mili3;
	//2. get input from user



	ifstream infile; //gets ready to open file
	infile.open("sos.txt"); //open the file

	int num;//we added a number at the top of the file to make this easier, this will hold it
	//read in the first number
	infile >> num; //read in the first number, use it to run the for loop!

	//reads in the rest of the characters from file
	for (int i = 0; i < num; i++) {
		infile >> mili; //temp storage
		mili2.push_back(mili); //push into the vector
	}

	//walks through the character vector
	for (iter1 = mili2.begin(); iter1 != mili2.end(); iter1++) {
		if (*iter1 == 'a' || *iter1 == 'A') {
			mili3.push_back(A); //push "alpha" into the string vector
		}
		//25 more if statements here



		if (*iter1 == 'b' || *iter1 == 'B') {
			mili3.push_back(B); //push "alpha" into the string vector


		}

		if (*iter1 == 'c' || *iter1 == 'C') {
			mili3.push_back(C); //push "alpha" into the string vector

		//25 more if statements here


			if (*iter1 == 'D' || *iter1 == 'D') {
				mili3.push_back(D); //push "alpha" into the string vector

			//25 more if statements here
			}

			if (*iter1 == 'e' || *iter1 == 'E') {
				mili3.push_back(E); //push "alpha" into the string vector
			}

			if (*iter1 == 'f' || *iter1 == 'F') {
				mili3.push_back(F); //push "alpha" into the string vector
			}
			//25 more if statements here

			if (*iter1 == 'g' || *iter1 == 'G') {
				mili3.push_back(G); //push "alpha" into the string vector
			}

			if (*iter1 == 'h' || *iter1 == 'H') {
				mili3.push_back(H); //push "alpha" into the string vector
			}


			if (*iter1 == 'i' || *iter1 == 'I') {
				mili3.push_back(I); //push "alpha" into the string vector
			}

			if (*iter1 == 'j' || *iter1 == 'J') {
				mili3.push_back(J); //push "alpha" into the string vector
			}

			if (*iter1 == 'k' || *iter1 == 'K') {
				mili3.push_back(K); //push "alpha" into the string vector
			}

			if (*iter1 == 'l' || *iter1 == 'L') {
				mili3.push_back(L); //push "alpha" into the string vector
			}

			if (*iter1 == 'm' || *iter1 == 'M') {
				mili3.push_back(M); //push "alpha" into the string vector
			}

			if (*iter1 == 'n' || *iter1 == 'N') {
				mili3.push_back(N); //push "alpha" into the string vector
			}

			if (*iter1 == 'o' || *iter1 == 'O') {
				mili3.push_back(O); //push "alpha" into the string vector
			}

			if (*iter1 == 'p' || *iter1 == 'P') {
				mili3.push_back(P); //push "alpha" into the string vector
			}
			//25 more if statements here

			if (*iter1 == 'q' || *iter1 == 'Q') {
				mili3.push_back(Q); //push "alpha" into the string vector
			}
			//25 more if statements here

			if (*iter1 == 'r' || *iter1 == 'R') {
				mili3.push_back(S); //push "alpha" into the string vector
			}
			//25 more if statements here


			if (*iter1 == 's' || *iter1 == 'S') {
				mili3.push_back(S); //push "alpha" into the string vector
			}
			//25 more if statements here


			if (*iter1 == 't' || *iter1 == 'T') {
				mili3.push_back(T); //push "alpha" into the string vector
			}
			//25 more if statements here

			if (*iter1 == 'u' || *iter1 == 'U') {
				mili3.push_back(U); //push "alpha" into the string vector
			}
			//25 more if statements here

			if (*iter1 == 'v' || *iter1 == 'V') {
				mili3.push_back(V); //push "alpha" into the string vector
			}

			if (*iter1 == 'w' || *iter1 == 'W') {
				mili3.push_back(W); //push "alpha" into the string vector
			}

			if (*iter1 == 'x' || *iter1 == 'X') {
				mili3.push_back(X); //push "alpha" into the string vector
			}

			if (*iter1 == 'y' || *iter1 == 'Y') {
				mili3.push_back(Z); //push "alpha" into the string vector

				if (*iter1 == 'z' || *iter1 == 'Z') {
					mili3.push_back(Z); //push "alpha" into the string vector
				}
				//25 more if statements here

			}
		}
		//4. print it

		ofstream write;
		write.open("changedSOS.txt");
		for (iter2 = mili3.begin(); iter2 != mili3.end(); iter2++) {//walk through the string array
			write << *iter2 << endl; //write each slot to the text file
		}
		write.close();

	}
	return 1;
}