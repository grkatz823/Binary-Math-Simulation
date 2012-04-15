//Greg Katz
#include <iostream>
#include <string>
#include "FinalProjMain.h"

using namespace std;

//main function
FinalProjMain::FinalProjMain(bool isTrue1,bool isTrue2,bool isTrue3,string num1,string num2,double base,double exponent)
{
	bool isTrue = true;
	double i = 0;
	char Q = '0';
	char choice = '0';
while(isTrue){

//if there is no set test, the interactive menu will be used
    if(isTrue1 == false && isTrue2 == false && isTrue3 == false){
	cout<<"1) Binary Multiplication"<<endl;
	cout<<"2) Binary Division"<<endl;
	cout<<"3) IEEE Floating Point"<<endl;
	cout<<"Input number: ";
	cin>>choice; 
	cout<<""<<endl;}

if(isTrue1 == true || choice == '1')
	{
//Only used if there is no set test
	if(choice == '1'){
	 cout<<"Correct input and whole integers are assumed"<<endl;
	 cout<<"Input Base# (2-16): ";
	 cin>>base;
	 cout<<"Input First Number: ";
	 cin>>num1;
	 cout<<"Input Second Number: ";
	 cin>>num2;}

/*Calls to various Mult.cpp functions to perform binary multiplication
Sets the function to the two decimal numbers to make binary strings.
Evens the digits in said strings and checks if it is negative.
If it is negative, gets the twos complement. Finally, prints
out a blankstring and sets up the binary multiplication table.*/
	 decNum1=m.convertToDecimalInt(num1,base);
	 decNum2=m.convertToDecimalInt(num2,base);
	 binNum1=m.convertToBin(decNum1);
	 binNum2=m.convertToBin(decNum2);
	 binNum1='0' + m.evenNum(binNum1,binNum2);
	 binNum2= m.evenNum(binNum2,binNum1);
	 negOne=m.findIfPos(decNum1);
	 negTwo=m.findIfPos(decNum2);
	 binNum1=m.getTwosComp(binNum1,negOne);
	 binNum2=m.getTwosComp(binNum2,negTwo);
	 BlankString = m.getA(binNum1);
	 cout<<"A	Q	Q-1"<<endl;
	 cout<<BlankString + "	" + binNum1 + "    " + Q<<endl;

/*Keeps a count of the number of steps necessary and steps through the process
printing out the result each time and resetting the inputs*/
	 while(i<BlankString.length()){
		fullAnswer=m.stepThroughMult(binNum1,binNum2,BlankString,Q);
		Q = fullAnswer.at(fullAnswer.length()-1);
		BlankString = fullAnswer.substr(0,BlankString.length());
		binNum1 = fullAnswer.substr(fullAnswer.length()/2,binNum1.length());
		cout<<BlankString + "	" + binNum1 + "    " + Q<<endl;
		i++;
		}

/*Places the answer into their variable, sets them back into their original base
and prints it out.*/
	fullAnswer = BlankString + binNum1;
	decAnswer = m.getNumericAnswer(fullAnswer);
	origAnswer = m.getOrigAnswer(decAnswer, base);
	cout<<""<<endl;
	cout<<"Using base ";
	cout<<base<<endl; //Had to separate because it created errors when put together
	cout<<"The product of " + num1 + " and " + num2 + " is " + origAnswer<<endl;
	}
else if(isTrue2 == true || choice == '2')
	{
	if(choice == '2'){
//Only asks for inputs if there is no set test
	 cout<<"Correct Input and whole integers are assumed"<<endl;
	 cout<< "(Negatives are accepted but binary division is done assuming no negatives)"<<endl;
	 cout<<"Input Base# (2-16): ";
	 cin>>base;
	 cout<<"Input First Number: ";
	 cin>>num1;
	 cout<<"Input Second Number: ";
	 cin>>num2;}

/*Converts the input strings into decimal numbers and takes the possible negative numbers problem
, checks whether they are negative makes them positive if they are and 
then converts it to a binary string*/
	 decNum1=m.convertToDecimalInt(num1,base);
	 decNum2=m.convertToDecimalInt(num2,base);

	 negOne=m.findIfPos(decNum1);
	 negTwo=m.findIfPos(decNum2);

	 decNum1=m.makePositive(decNum1,negOne);
	 decNum2=m.makePositive(decNum2,negTwo);

	 binNum1=m.convertToBin(decNum1);
	 binNum2=m.convertToBin(decNum2);

	 binNum1= m.evenNum(binNum1,binNum2);
	 binNum2= m.evenNum(binNum2,binNum1);

/*Checks for any possible overflow problems and eliminates them
then creates the blankstring sets up the binary division table*/
	 if((binNum1.at(0) == '1' && binNum2.at(0) == '1')||
	    (binNum2>binNum1)){
		binNum1 = '0' + binNum1;
		binNum2 = '0' + binNum2;}
	 BlankString = m.getA(binNum1);
	 cout<<"A	Q	"<<endl;
	 cout<<BlankString + "	" + binNum1<<endl;

/*Keeps a count of the number of steps necessary and steps through the process
printing out the result each time and resetting the inputs*/
	while(i<BlankString.length()){
		fullAnswer=m.stepThroughDiv(binNum1,binNum2,BlankString);
		BlankString = fullAnswer.substr(0,BlankString.length());
		binNum1 = fullAnswer.substr(fullAnswer.length()/2,binNum1.length());
		cout<<BlankString + "	" + binNum1<<endl;
		i++;
		}

/*Takes the binary string answer and converts it to the base answer
If there were negative, it places them at the beginning of the string
and then prints out the answer.*/
	decAnswer = m.getNumericDivAnswer(BlankString);
	origAnswer = m.getOrigAnswer(decAnswer, base);
	decAnswer2 = m.getNumericDivAnswer(binNum1);
	origAnswer2 = m.getOrigAnswer(decAnswer2, base);
	if((negOne==false && negTwo==true)||(negOne==true && negTwo==false)){
	origAnswer2 = '-' + origAnswer2;}
	cout<<""<<endl;
	cout<<"Using base ";
	cout<<base<<endl; //Had to separate because it created errors when put together
	cout<<"The quotient of " + num1 + " and " + num2 + " is " + origAnswer2<<endl;
	cout<<"The remainder is " + origAnswer<<endl;


	}
else if(isTrue3 ||choice == '3')
	{
	if(choice == '3'){
	 cout<<"Input Base# (2-16):";
	 cin>>base;
	 cout<<"Correct Input assumed (Decimals and negatives allowed)"<<endl;
	 cout<<"Input Number:";
	 cin>>num1;
	 cout<<"Please enter exponent only for special cases. Otherwise, input 0"<<endl;
	 cout<<"Watch out for overflows as well"<<endl;
	 cout<<"Input Exponent: ";
	 cin>>exponent;}

/*Separates the string into before and after decimal point
and converts them each to binary through their respective methods.
Finds the floating point exponent as well as the sign bit.*/
	 numBig= m.getNumBefore(num1);
	 numSmall=m.getNumAfter(num1);
	 decNumFloat=m.convertToDecimalInt(numBig,base);
	 binNum1=m.convertToBin(decNumFloat);
	 smallFloat2=m.convertDecimalToBase10(numSmall,base);
	 binNum2 = m.convertDecFloatToBin(smallFloat2);
	 negOne=m.findIfPos(decNumFloat);
	 exponent += binNum1.length()-1 + 127;
	 floatExponent = m.convertToBin(exponent);
	 while(floatExponent.length() != 8){
		floatExponent = '0' + floatExponent;}
	 binNum1= binNum1.substr(1) + binNum2;

/*Adds in the zeroes necessary for IEEE form them inserts the
exponent and sign bits, then prints out the answer*/
	while(binNum1.length() != 23){
		if(binNum1.length()>23){
		 binNum1 = binNum1.substr(0,23);}
		else{
		 binNum1 += '0';}}
	binNum1 = floatExponent + binNum1;	
	if(negOne == 0){
	binNum1 = '1' + binNum1;}
	else{
	binNum1 = '0' + binNum1;}

	cout<<""<<endl;
	cout<<"Using base ";
	cout<<base<<endl;
	cout<<"The IEEE Floating Point of " + num1 + " is:"<<endl;
	cout<<binNum1<<endl;
	

	}
else{
	cout<<"Bad Input"<<endl;
	}
	if(isTrue1 == false && isTrue2 == false && isTrue3 == false){
	cout<<""<<endl;
	cout<<"Would you like to continue using this project? (y/n)"<<endl;
		cin>>contin;
		if(contin=="y"){
		i = 0;
		Q = '0';}
		else if(contin=="n"){
		isTrue=false;
			}
	}else{
		isTrue=false;}
	}
}

		
