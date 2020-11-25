// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

#define MINSequenceLen 3//Define for minimum sequence for the length   
#define toDigit(c) (c-'0')

bool palindrome(string num) {//use for INeger conversion only(but will ignore leading zero "0")

	int digit, rev = 0;
	int NumINt = stoi(num);
	cout << "palindrome Number: " << NumINt << "\n";
	do
	{
		digit = NumINt % 10;
		rev = (rev * 10) + digit;
		NumINt = NumINt / 10;
	} while (NumINt != 0);
	if (NumINt == rev)
		return true;
	else
		return false;

	return 0;

}


bool ExPalindrome(string num) {

	int flag = 0;
	int i, length;

	for (i = 0;i < num.size();i++) {
		if (num[i] != num[num.size() - i - 1]) {
			flag = 1;
			break;
		}
	}
		if (flag) return false;
		else return true;
		return 0;

	}

int main()
{
	string InputNumbSTR;
	cout << "Enter a natural number:"; cin >> InputNumbSTR;
	cout << "Working...\n";

	int TotalCount = 0;
	int NumIndex = 0;
	int SequenceCounted = MINSequenceLen;
	for (char i = 0; i < InputNumbSTR.size(); i++) {//loop every number
		//printf("NumerLooping: %i \n", toDigit(InputNumbSTR[i]));
		
		string NumbToCheck = "";
		if (MINSequenceLen >= InputNumbSTR.size()-1) break;//stop the loop end of characters
		//std::cout << NumbToCheck << "\n";
		
		if (SequenceCounted > InputNumbSTR.size()) {
			i = 0;//out of range
			SequenceCounted = SequenceCounted - NumIndex+1;
			if (NumIndex <= 1) break;//end of check
			NumIndex = 0;
		}
		for (int ii = i; ii < SequenceCounted; ii++) {
			NumbToCheck.append(std::to_string(toDigit(InputNumbSTR[ii])));//add number range to list
		}
		
		if (ExPalindrome(NumbToCheck) == true){
			TotalCount++;
			std::cout << "Sequence Number Found: " << NumbToCheck << "\n";
		}else {
			//std::cout << "Number " << NumbToCheck << " Is not sequence\n";
		}
		SequenceCounted++;
		NumIndex++;
	}
	std::cout << "Total Sequences Found:  " << TotalCount << "\n";
}

