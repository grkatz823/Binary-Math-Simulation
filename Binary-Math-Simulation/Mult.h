/**Greg Katz
Final Project cs324
Simulating Binary Multiplication
*/

#include <string>
#include <stack>
using namespace std;

class Mult
{
	public:
//function called by the Final Project
	Mult();
	double convertToDecimalInt(string str, double base);
	string convertToBin(double num);
	string evenNum(string str1, string str2);
	bool findIfPos(double num);
	string getTwosComp(string str,bool positive);
	string getA(string binNum);
	string stepThroughMult(string binNum1,string binNum2,string BlankString,char Q);
	double getNumericAnswer(string str1);
	double getNumericDivAnswer(string str1);
	string getOrigAnswer(double num, double base);
	string stepThroughDiv(string binNum1,string binNum2,string BlankString);
	double makePositive(double number, bool positive);
	string getNumBefore(string num);
	string getNumAfter(string num);
	double convertDecimalToBase10(string str,double base);
	string convertDecFloatToBin(double smallFloat2);

	private:
//functions used only in Mult.cpp
	string binaryAdd(string str1,string str2);
	
};
