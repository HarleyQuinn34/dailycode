#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
	int integers;
	int fox;
	//1. set up vector
	vector<int> numbers;

	//2. get input from user
	cout << "Please enter in integers (0 to stop): ";
	while (cin >> integers) {
		if (integers == 0) {
			break;
		}
		numbers.push_back(integers);  //Moved after the check to not inclue 0

	}
	//3. call the sort function
	sort(numbers.begin(), numbers.end());

	//4. print it
	int y = numbers.size();
	for (int i = 0; i < y; i++) {
		cout << numbers[i] << " ";
	}

	return 0;
}