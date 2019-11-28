// COMP375HW2-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program's purpose is to find the largest integer in an array called arrayA
// Written by John Orekunrin

#include <iostream>

using namespace std;

int main(int argn, char* argv[])
{
	int largest, i, arrayA[12];
	cout << "Enter 10 numbers \n";
	for (i = 0; i < 10; i++) {
		cin >> arrayA[i];
	}
	_asm {
		lea eax, arrayA
		mov ebx, 0
		mov ecx, 0

		search:
		cmp ebx, [eax]
			jl greaterComp
			jmp repeat

			greaterComp :
		mov ebx, [eax]
			jmp repeat
			repeat :
		inc ecx
			add eax, 4
			cmp ecx, 10
			jl search
			jmp fin

			fin :
		mov largest, ebx
	}
	cout << "The largest value is " << largest << endl;
	return 0;

}