#ifndef GAME_HH
#define GAME_HH

#include "board.hh"

/*
* Plik zawiera funkcje potrzebne do obsługi gry w kółko i krzyżyk
*/

#define MAX(a,b) (a>=b)?a:b //makro zwraca większą z dwóch liczb
#define MIN(a,b) (a<=b)?a:b //makro zwraca mniejszą z dwóch liczb

/*
* Funkcja pokazuje komunikat startowy
*/
void startGame();
/*
* Funkcja sprawdza, czy uzytkownik chce grać jeszcze raz
*/
bool onceMore();
/*
*Funkcja obsługuje ruchy użytkownika
*/
void playerMove(Board &b);
/*
*Algorytm minimax z alfa-beta cięciami
* char sign - znak analizowanego gracza
* int depth - głębokość przeszukiwania
* int alpha - parametr alfa
* int beta  - parametr beta
* Board& b - plansza do gry przekazana przez referencje
*/
int minimax(char sign, int depth, int alpha, int beta, Board& b);
/*
* Funkcja obsługuje ruchy komputera przy pomocy algorytmu minimax
*/
void computerMove(Board& b);

#endif //GAME_HH