#include "board.hh"
using namespace std;

char& Board::operator()(int i, int j){
    return array[i][j];
}

void Board::clearBoard(){
    //wypełnienie tablicy spacjami
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            array[i][j]=' ';
        }
    }
}

void Board::display(){
    system("CLS");           //czyszczenie ekranu konsoli
    //Wyświetlenie planszy do gry w kółko i krzyżyk w sposób czytelny dla gracza
    for(int i=0;i<s;i++){
        cout<<" "<<i<<"  ";
    }
    cout<<endl;
    for(int i=0;i<s;i++){
        cout<<i;
        for(int j=0;j<s;j++){
            cout<<' '<<array[i][j]<<' ';
            if(j!=s-1){
                cout<<'|';
            }
        }
        cout<<endl;
        if(i!=s-1){
            cout<<'-';
            for(int k=0;k<s;k++){
                cout<<"---+";
            }
        }
        cout<<endl;
    }
}

bool Board::emptyPlaces(){
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(array[i][j]==' '){ return true;} //zwraca true jesli napotka spację
        }
    }
    return false;
}

bool Board::win(char sign){
    int start;     //zmienna pomocnicza - punkt startowy
    bool yes=true; //zmienna pomocnicza
    //kolumny i wiersze
    for(int i=0;i<s;i++){
        start=0; //punkt startowy (rząd 0)
        //Dopóki jest szansa na znalezienie wygranej:
        while(start<=s-signsToWin){
            yes=true;
            //pętla wykonuje 'signsToWin' powtórzeń
            for(int j=start;j<start+signsToWin;j++){
                if(array[i][j] != sign){
                    yes=false; //ustawienie zmiennej na false
                    break; //przerwanie pętli w przypadku nieprawidłowego znaku
                }
            }
            if(yes) return yes; //zwracanie true w przypadku wygranej
            start++; //jesli nie znaleziono wygranej - przesun punkt startowy
        }
    }
    for(int i=0;i<s;i++){
        start=0; //punkt startowy (kolumna 0)
        //Dopóki jest szansa na znalezienie wygranej:
        while(start<=s-signsToWin){
            yes=true;
            //Pętla wykonuje 'signsToWin' powtórzeń
            for(int j=start;j<start+signsToWin; j++){
                if(array[j][i]!=sign){
                    yes=false; //ustawienie zmiennej na false
                    break;     //przerwanie pętli w przypadku nieprawidłowego znaku
                }
            }
            if(yes) return yes; //zwracanie true w przypadku wygranej
            start++;            //jesli nie ma wygranej - przesuń punkt startowy
        }
    }
    //przekatne
    //Pętla działa dopóki jest szansa na znalezienie wygranej
    //Zmienne i, j pełnią funkcję punktu startowego
    for(int i=0;i<=s-signsToWin;i++){
        for(int j=0;j<s;j++){
            //pierwszy przypadek
            if(i+signsToWin-1<s && j+signsToWin-1<s){
                yes=true;
                //szukanie wygranej
                for(int k=0;k<signsToWin;k++){
                    if(array[i+k][j+k]!=sign){
                        yes=false; //ustawienie na false
                        break;     //przerwanie w przypadku nieprawidłowego znaku
                    }
                }
                if(yes) return yes; //zwracanie true jeśli gracz ma wygraną
            //drugi przypadek
            }else if(i+signsToWin-1<s && j-signsToWin+1>=0){
                yes=true;
                for(int k=0;k<signsToWin;k++){
                    if(array[i+k][j-k]!=sign){
                        yes=false;  //ustawienie false
                        break;      //przerwanie w przypadku nieprawidłowego znaku
                    }
                }
                if(yes) return yes; //zwracanie true w przypadku wygranej
            }
        }
    }
    return false; //jesli nie udało się znaleźć wygranej zwraca false
}

Board::Board(){
    do{
        cout<<"Podaj rozmiar planszy: ";
        cin>>s;
        cin.clear();
    }while(s<3); //minimalny rozmiar planszy to 3
    do{
        cout<<"Podaj liczbe znakow w rzedzie: ";
        cin>>signsToWin;
        cin.clear();
    }while(signsToWin<3); //minimalna liczba znaków do wygrania to 3

    //przydzielenie pamięci do tablicy dynamicznej
    array = new char*[s];
    for(int i=0;i<s;i++){
        array[i] = new char[s];
    }
}
Board::~Board(){
    //zwolnienie pamięci
    for(int i=0;i<s;i++){
        delete[] array[i];
    }
}