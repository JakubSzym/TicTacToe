#ifndef BOARD_HH
#define BOARD_HH

#include<iostream>
#include<stdlib.h>
#include<conio.h>

/*
* Plik zawiera klasę Board, która jest implementacją planszy do gry w kółko i krzyżyk
*/

class Board{
private:
    int s;                 //rozmiar planszy
    int signsToWin;        //liczba znakow w rzedzie, kolumnie lub po przekątnej potrzebna by wygrać
    char** array;          //wskaźnik do  tablicy dynamicznej do wstawiania znaków obu graczy
public:
    /*
    * Metoda wypełnia planszę znakami spacji
    */
    void clearBoard();
    /*
    * Metoda wyświetla planszę do gry w kółko i krzyżyk
    */
    void display();
    /*
    * Przeciążenie operatora () ułatawiające dostęp do elementów tablicy array
    * int i, j - indeksy
    */
    char& operator ()(int i, int j);
    /*
    * Metoda zwraca "true"  jeżeli występują na planszy puste miejsca
    */
    bool emptyPlaces();
    /*
    * Metoda zwraca rozmiar planszy przez referencje
    */
    int& size(){ return s;}
    /*
    * Metoda sprawdza, czy gracz z odpowiednim znakiem ma wygraną
    * sign - znak analizowanego gracza
    */
    bool win(char sign);
    /*
    * konstruktor
    * Przydziela odpowiednią ilość pamięci do tablicy array
    * Pyta się użytkownika o ustalenie wartości SignsToWin
    */
    Board();

    /*
    *destruktor
    *zwalnia pamięć po tablicy dynamicznej
    */
    ~Board();
};


#endif //BOARD_HH