#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

string delSpace(string sIn);
string oblicz(string sWyr);
string simple_calculations(string sEkspression);
int cntInString(string sIn, char cSymbol);

int main(){
   bool pop = true; //poprawność wpisanego wyrażenia
   int iBrackets = 0; // nawiasy
   short int iLastChar = -1, iCurrentChar = 0; // 1-liczba, 2-operator, 3-nawias
	string s_wyr; //wyrażenie
	string sNumbers = "1234567890"; //cyfry
	string sOperators = "^*/+-"; // operatory
	string sBrackets = "()"; // nawiasy
	string sOthers = ".,"; // inne
	string sCorrect = sNumbers; sCorrect +=sOperators ;sCorrect +=sBrackets; sCorrect += sOthers; //dopuszczalne znaki
   cout << "******************************************************************\n" <<
   		  "******************************************************************\n" <<
   		  "************************* Kalkulator *****************************\n" <<
   		  "*************** created by Krzysztof Szydłowski ******************\n" <<
   		  "******************* 2009 All right reserved **********************\n" <<
   		  "******************************************************************\n" <<
   		  "******************************************************************\n";
	do{
		pop = true;
		iBrackets=0; iLastChar = -1; iCurrentChar = 0;
		cout << "Wprowadź wyrażenie: ";
		cin >> s_wyr;
		cin.ignore();
		
			for(unsigned int i=0; i<s_wyr.length(); i++){
				if(cntInString(sNumbers, s_wyr.at(i))!=0){
					iCurrentChar = 1;
				}
				else if(cntInString(sOperators, s_wyr.at(i))!=0){
					iCurrentChar = 2;
				}
				else if(s_wyr.at(i)=='('){
					iBrackets++;
					iCurrentChar = 3;
				}
				else if(s_wyr.at(i)==')'){
					iBrackets--;
					iCurrentChar = 4;
				}
				else if(cntInString(sOthers, s_wyr.at(i))!=0){
					iCurrentChar = 5;
						if(s_wyr.at(i)==','){
							s_wyr.at(i)='.';
						}
				}
				else{
					pop = false;
					break;
				}

				if(iLastChar==iCurrentChar && (iCurrentChar == 2 || (iLastChar==3 && iCurrentChar==1) ||
					(iLastChar==1 && iCurrentChar==3) || (iLastChar==3 && iCurrentChar==4) || (iLastChar==4 && iCurrentChar==3))){
					pop = false;
				}
				
				iLastChar=iCurrentChar;
			}
			if(iBrackets!=0){
				pop = false;
			}
			if(pop==false){
				s_wyr.clear();
			}
		}while(pop==false);
		
	cout << endl << s_wyr << "=" << oblicz(s_wyr) << endl;
	return 0;
}

//******************************************************************************
string oblicz(string sWyr){
	int w_left=-1, w_right=-1; // wskażniki na początek i koniec nawiasu
		for(unsigned int i=0; i < sWyr.length(); i++){
			if(sWyr.at(i)=='('){
				w_left=i;
			}
			else if(sWyr.at(i)==')'){
				w_right=i;
			}
			if(w_left!=-1 && w_right!=-1){
				sWyr.replace(w_left, w_right-w_left+1, simple_calculations(sWyr.substr(w_left+1, w_right-w_left-1)));
				w_left = -1; w_right=-1; i=-1;
			}
		}
	return simple_calculations(sWyr);
}
string simple_calculations(string sExpression){
	string sOperators = "^*/+-", w, sA, sB;
	int l=-1, r=-1, j;
	char action;
	double dA, dB, wynik;
	stringstream ss;
	bool end = false;
	cout << "l\tr\tlo\takt\ta\tb\tw\tcaly\tnowy\n";
	for(int i = 0; i < 5; i++){
		for(unsigned int z = 1; z < sExpression.length(); z++){
			j = z;
			if(i==0) j = sExpression.length()-z-1;
			if( (i==3 && (sExpression.at(j)==sOperators.at(i) || sExpression.at(j) == sOperators.at(i+1))) ||
				 sExpression.at(j)==sOperators.at(i)){
				 if(sExpression.at(j)==sOperators.at(i)){
				 	action = sOperators.at(i);
				 }
				 else{
				 	action = sOperators.at(i+1);
				 }
				for(int left=j-1; left>=0; left--){
					if(!isdigit(sExpression.at(left)) && sExpression.at(left)!='.'){
						l = left; break;
					}
				}
				if((l>0 && isdigit(sExpression.at(l-1))) || l==-1) l++;

				for(unsigned int right=j+1; right<sExpression.length(); right++){
					if(!isdigit(sExpression.at(right)) && sExpression.at(right)!='.'){
						r = right; break;
					}
				}
				if(r==-1) r=sExpression.length();

				sA = sExpression.substr(l, j-l); //wyciągnięcie 1. liczby z całego stringa
				sB = sExpression.substr(j+1, r-j-1); // wyciągnięcie 2. liczby z całego stringa
				ss.clear();	ss << sA; ss >> dA; //konwersja 1. liczby string -> double
				ss.clear(); ss << sB; ss >> dB; //konwersja 2. liczby string -> double
				
					switch(action){
						case '^': wynik = pow(dA, dB); break;
						case '*': wynik = dA*dB; break;
						case '/': (dB==0?end == true: wynik = dA/dB); break;	 
						case '+': wynik = dA+dB; break;
						case '-': wynik = dA-dB; break;
					}
				ss.clear(); ss << wynik; ss >> w; // konwersja wyniku double -> string
					if(w[0]=='+' || w[0]==' ' || w[0]=='*' || w[0]=='^') w.erase(0,1);cout << l << "\t" << r << "\t" << r-l << "\t" << sExpression.substr(l, r-l) << "\t"  << dA<< "\t" << dB << "\t" << w << "\t" << sExpression;
				sExpression = delSpace(sExpression.replace(l, r-l, w));				
				

				 cout << "\t" <<sExpression << endl;
				dA=0; dB=0; l=-1; r=-1, wynik = 0; z=0;
					if(cntInString(sExpression, '-')==1 && sExpression.at(0)=='-' && cntInString(sExpression, '+')==0 &&
						cntInString(sExpression, '^')==0	&& cntInString(sExpression, '*')==0 && cntInString(sExpression, '/')==0){
							end=true; break;
					}
			}
		}
		if(end==true) break;
	}
	return sExpression;
}
string delSpace(string sIn){
	string sOut;
	for(unsigned int i=0; i < sIn.length(); i++){
		if(sIn[i]!=' ') sOut+=sIn[i];
	}
	return sOut;
}
int cntInString(string sIn, char cSymbol){
	int iTemp=0;
	for(unsigned int i=0;i<sIn.length();i++){
		if(sIn.at(i)==cSymbol) iTemp++;
	}
	return iTemp;
}
