#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPerfect(int num);
bool isPrime(int num);

int main()
{
	string userInput;
	vector<int> perfectNumbers;
	vector<int> primeNumbers;
	int inputToInt{ 0 };
	int incrament{ 2 };
	while (userInput != "exit")
	{
		cout << "Please enter a number greater than two or type \"exit\" to exit: ";
		cin >> userInput;

		inputToInt = stoi(userInput);

		if (inputToInt < 2) //checks if input is less than two, changes the input to 2 to avoid exceptions
		{
			cout << "number must be 2 or greater\n\n";
			inputToInt = 2;
		}

		cout << "Prime Numbers:\n";

		do
		{
			if (isPrime(incrament) == true)
				primeNumbers.push_back(incrament);
			incrament++;
		} while (incrament != inputToInt);

		for (int i = 0; i < primeNumbers.size(); i++)
			cout << primeNumbers[i] << ", ";
		cout << endl;

		for (int i = 2; i < inputToInt; i++)
			if (isPerfect(i))
				perfectNumbers.push_back(i);

		cout << "Perfect numbers:\n";

		for (int i = 0; i < perfectNumbers.size(); i++)
			cout << perfectNumbers[i] << ", ";
		cout << endl;

		userInput = "";
		perfectNumbers.clear();
		primeNumbers.clear();

	}
	return 0;
}

bool isPerfect(int num)//checks if a number is a perfect number
{
	vector<int> devisers;
	int sum{ 0 };
	for (int i = 1; i < num; i++)
	{
		if (i != num && num % i == 0)
			devisers.push_back(i);
	}
	for (int i = 0; i < devisers.size(); i++)
		sum += devisers[i];

	if (num == sum)
		return true;
	else
		return false;
}

bool isPrime(int num)
{
	bool isPrime{ true };
	for (int i = 2; i < num; i++)
	{
		if (i != num && num % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	if (isPrime)
		return true;
	else
		return false;

}