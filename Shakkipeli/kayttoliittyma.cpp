#include "kayttoliittyma.h"
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <iostream>
#include "siirto.h"
#include <string>
#include "ruutu.h"
#include <regex>
#include "myNames.h"
#include <process.h>
#include "screenResetThreading.h"
#include <conio.h> //_keyboard hit and buffer creation
#include <vector>
#include "history.h"
#include "evaluonti.h"

using namespace myNames;
extern wstring tmp_input_s; //the input string buffer we use in the printed screen as player input
extern vector<History*> * siirto_historia_s;
extern Asema * lauta_s;


Kayttoliittyma::Kayttoliittyma(Asema * _asema)
{
	asema = _asema;
}

void Kayttoliittyma::piirraLauta(wstring _text, wstring tmp_input)
{	
	static bool isBeingUsed;

	//loop around here waiting for your turn to draw the screen####
	while (isBeingUsed)
	{
	}
	//#############################################################

	isBeingUsed = true; //we set this to true so that none of the threads can use this function as long as the screen is being drawn somewhere else
	
	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT); //what??

	int row = 8;
	int history_rows = siirto_historia_s->size(); //we use this before the history is filled with 8 moves
	int  overflow = 8; //we use this when the history is full

	wcout << L"   a  b  c  d  e  f  g  h                           [    Move history   ]";

	for (int y = 7; y >= 0; y--) //x row
	{
		wcout << L"\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //switch bg_colour
		wcout << row << L" "; //we print the row character;

		for (int x = 0; x < 60; x++) //y row
		{

			if ((x + y) % 2) //"every other square"
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
			}
			if (x < 8)
			{
				if (asema->lauta[x][y] != NULL) //if the square is not empty, print whatever is in there using its unicode. Else print nothing
				{
					wcout << L" " << asema->lauta[x][y]->getUnicode() << L" ";
					//wcout << L" " << x << y << L" ";
				}
				else
				{
					wcout << L"   ";
				}
			}
			if (x == 8) //chess board end row number
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
				wcout << L" " << row << L" ";
			}; //we print the row character;
			if (x >= 52) //empty space between move history and chess board
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
				wcout << L"   ";
			};
			if (x == 59 && siirto_historia_s->size() > 0) //HERE WE PRINT THE ACTUAL MOVEMENT HISTORY
			{
				if (history_rows > 0 && history_rows <= 8) //IF THERE IS HISTORY TO BE PRINTED
				{
					char first = siirto_historia_s->at(siirto_historia_s->size() - history_rows)->siirto_h->getAlkuruutu()->getSarake() + 'a'; // siirto_historia_s->at(siirto_historia_s->size() - history_rows).siirto_h.getAlkuruutu()->getSarake() + 'a'; //first number as alphabet
					char second = siirto_historia_s->at(siirto_historia_s->size() - history_rows)->siirto_h->getLoppuruutu()->getSarake() + 'a'; //second number as alphabet

					if ((x + y) % 2) //"every other square"
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
					}

					wstring nabula_nimi = siirto_historia_s->at(siirto_historia_s->size() - history_rows)->nabula_h != NULL ? siirto_historia_s->at(siirto_historia_s->size() - history_rows)->nabula_h->getUnicode() : L"";
					wcout
						<< siirto_historia_s->size() - history_rows //HISTORY NUMBER
						<< L":   From "
						<< first
						<< siirto_historia_s->at(siirto_historia_s->size() - history_rows)->siirto_h->getAlkuruutu()->getRivi() + 1
						<< L" to "
						<< second
						<< siirto_historia_s->at(siirto_historia_s->size() - history_rows)->siirto_h->getLoppuruutu()->getRivi() + 1
						<< L"   ";
						
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

						wcout << L"   " << nabula_nimi;

					history_rows--;
				}
				if (siirto_historia_s->size() > 8) //IF THE HISTORY AREA IS FULL, START TRUNCATING
				{
					char first = siirto_historia_s->at(siirto_historia_s->size() - overflow)->siirto_h->getAlkuruutu()->getSarake() + 'a'; //first number as alphabet
					char second = siirto_historia_s->at(siirto_historia_s->size() - overflow)->siirto_h->getLoppuruutu()->getSarake() + 'a'; //second number as alphabet

					if ((x + y) % 2) //"every other square"
					{
						asema->getSiirtoVuoro() == 1 ? SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY) : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

					}
					else
					{
						asema->getSiirtoVuoro() == 1 ? SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED): SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
					}
					wstring nabula_nimi = siirto_historia_s->at(siirto_historia_s->size() - overflow)->nabula_h != NULL ? siirto_historia_s->at(siirto_historia_s->size() - overflow)->nabula_h->getUnicode() : L"";
					wcout
						<< (siirto_historia_s->size() - overflow) //HISTORY NUMBER
						<< L":   From "
						<< first
						<< siirto_historia_s->at(siirto_historia_s->size() - overflow)->siirto_h->getAlkuruutu()->getRivi() + 1
						<< L" to "
						<< second
						<< siirto_historia_s->at(siirto_historia_s->size() - overflow)->siirto_h->getLoppuruutu()->getRivi() + 1
						<< L"";

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

					wcout << L"   " << nabula_nimi;
					overflow--;
				}
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //switch bg_colour
		--row; //iterate row character down from h to a


	}

	//bottom row letters
	wcout << L"\n   a  b  c  d  e  f  g  h";
	wcout << L"\n";

	wcout << _text; //INFO TEXT (max 50 chars)

	//wcout << L"\n" << "Move: " << tmp_input;

	wstring player_turn_text = asema->getSiirtoVuoro() == 1 ? L"\nPlayer turn: WHITE\n" : L"\nPlayer turn: BLACK\n";
	wcout << player_turn_text;

	double aa = evaluoi(*lauta_s);
	wcout << "Aseman arvo: " << aa << L"\n";
	
	wcout << L"\n" << "Move: " << tmp_input;


	isBeingUsed = false; //release screen to be drawn again
}

void Kayttoliittyma::piirraLauta(wstring text)
{
	piirraLauta(text, tmp_input_s);
}

//empty info text (no overloads) piirraLauta
void Kayttoliittyma::piirraLauta()
{
	piirraLauta(L"", tmp_input_s);
}

Siirto * Kayttoliittyma::annaVastustajanSiirto()
{
	bool input_ready = false; //if input loop can go to syntax checking and shit the next time it is iterated
	wstring siirto_str;
	wregex c(L"([a-h])([1-8])([-])([a-h])([1-8])|[q]|[Q]"); //regex rules that we check

	//erase the first char if six chars in total
	if (siirto_str.length() > 5) { siirto_str.erase(0, 1); };



	while (1) //if the syntax is not in correct format, we keep asking the move until it is...then we continue
	{
		if (input_ready)
		{

			input_ready = false;
			siirto_str.length() > 5 ? siirto_str.erase(0, 1) : siirto_str; //if the input was 6 letters, remove the first one as it is not important

			//LINNOITUS HÄSSÄKÄT################
			if (siirto_str == L"0-0"){
				return new Siirto(true, false);
			}
			if (siirto_str == L"0-0-0"){
				return new Siirto(false, true);
			}
			//##################################

			if (regex_match(siirto_str, c))
			{

				if (siirto_str == L"q" || siirto_str == L"Q") //here we handle the "q" and "Q" inputs to quit the program
				{
					return new Siirto(Ruutu(666, 666), Ruutu(666, 666)); //we set the Siirto object to be from 666 to 666 so that the main function can also see that the player wants to end the program
				}

				int x1 = siirto_str[0] - 'a';
				int y1 = siirto_str[1] - '1';
				int x2 = siirto_str[3] - 'a';
				int y2 = siirto_str[4] - '1';

				//same square chek (player tried to move the square in its place and nowhere else)
				if (x1 == x2 && y1 == y2)
				{
					printText(L"That's the same goddamn square you idiot!");
				}
				else
				{
					//check that there actually is a piece there
					if (asema->lauta[x1][y1] == NULL)
					{
						//system("cls"); //CLEAR SCREEN FOR NEW FRAME
						tmp_input_s.erase();
						siirto_str.erase();
						printText(L"*sigh*...there's nothing there to move...");
					}
					else //EVERYTHING WAS FINE, CAN MOVE THE FUCKING PIECE OS SHIT TO MAIN AND HAVE IT MOVE THE GODDAMN PIECE
					{
						Siirto * tmp_siiirotoeot = new Siirto(Ruutu(x1, y1), Ruutu(x2, y2));
						return tmp_siiirotoeot; //returns the pointer to the object, remember to delete that shit later in main
					}
				}
			}
			else //syntax was absolute shit
			{
				tmp_input_s.erase();
				siirto_str.erase();
				printText(L"Incorrect syntax 2! Try again! (example: a1-c1)"); //update frame
			}
		}
		else
		{
			//HERE WE LOOPTY LOOP AS LONG AS IS NECESSARY TO GET THE PROPER INPUT OR WHEN THE PLAYER HAS PRESSED ENTER AND STOPPED THIS LOOPTY LOOP
			while (_kbhit()) //BUTTON PRESS! this following code is ran when button is pressed
			{
				tmp_input_s += _getch(); //add that char to the string, the button that was pressed I mean

				//HANDLE WHAT WAS TYPED
				if(GetAsyncKeyState(VK_RETURN)) //if the player presses enter, we accept the input and put it through syntax checking etc...
				{
					input_ready = true; //WE ARE READY TO CHECK THE SYNTAX
					tmp_input_s.pop_back(); //pop the enter out of the actual siirto_str
					siirto_str = tmp_input_s; //finalize the string
					tmp_input_s.erase(); //empty the temparary buffer
					break; //no reason to loop here anymore
				}
				if (tmp_input_s.size() >= 1)
				{
					if (GetAsyncKeyState(VK_BACK)) //BACKSPACE SHIT
					{
						tmp_input_s.pop_back(); //delete the backsapce itself
						tmp_input_s.size() > 0 ? tmp_input_s.pop_back():0; //delete last char if there is something to remove
					}
				}
				piirraLauta(info_text, tmp_input_s); //update the screen so that the character that the player just pressed actually shows up on the screen
			}
		}
	}
}

void Kayttoliittyma::printText(wstring stringgi)
{
	info_text = stringgi;
	piirraLauta(info_text); //update frame

	//THREADINGG SHIT FUCK YEAH BITCHES WE GONNA DO DIS!!!
	_beginthread(reset_Text_Thread, 0, NULL);
}

int Kayttoliittyma::kysyVastustajanVari()
{
	system("cls");
	wstring color;
	wcout << "What is the computer's color (white/black)? \nGief color: ";

	while (1)
	{
		while (_kbhit())
		{
			color += _getch();

			//HANDLE WHAT WAS TYPED
			if (GetAsyncKeyState(VK_RETURN)) //if the player presses enter, we accept the input and put it through syntax checking etc...
			{
				color.pop_back(); //pop the enter out
				if (color == L"white") { return 1; }
				else if (color == L"black") { return -1; }
			}
			if (color.size() >= 1)
			{
				if (GetAsyncKeyState(VK_BACK)) //BACKSPACE SHIT
				{
					color.pop_back(); //delete the backsapce itself
					color.size() > 0 ? color.pop_back() : 0; //delete last char if there is something to remove
				}
			}
			system("cls");
			wcout << "What is the computer's color (white/black)? \nGief color: " << color;
		}

	}

}