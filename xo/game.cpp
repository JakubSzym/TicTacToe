#include "game.hh"
#include <ctime>
#include <cstdlib>
using namespace std;

void startGame(){
    system("clear");
    cout<<"Gra w Kolko i Krzyzyk - czlowiek vs komputer"<<endl;
    cout<<"Autor: Jakub Szymkowiak"<<endl;
    cout<<"Nacisnij dowolny klawisz, by zagrac"<<endl;
}

bool onceMore(){
    cout<<"Czy chcesz zagrac rewanz? (Tak - T)"<<endl;
    char sign;
    cin >> sign;
    cin.clear();
    if(sign=='T' || sign=='t'){
        return true;
    }
    return false;
}

void playerMove(Board &b){
    int x, y; //indeksy
    bool error; //zmienna pomocnicza
    do{
        error=true;
        cout<<"Twoj ruch. Wprowadz wspolrzedne: ";
        cin>>x; //wprowadzenie  numeru rzędu
        cin.clear();
        cin>>y; //wprowadzenie numeru kolumny
        cin.clear();
        //sprawdzenie czy ruch jest możliwy
        if(x<b.size() && y<b.size()){
            if(b(x,y)==' '){
                b(x,y)='X'; //ustawienie znaku w odpowiednim miejscu
                error=false;
            }
        }
    }while(error); //jesli wykryto błąd, pytaj użytkownika do skutku
}

int minimax(char sign, int depth, int alpha, int beta, Board& b){
    int eval, maxEval; //zmienne pomocnicze
    //sprawdzenie, czy jest wygrana analizowanego gracza
    if(b.win(sign)){
        return sign == 'X' ? -10:10;
    }
    //jezeli jest remis lub głębokość osiągnęła poziom 0
    if(!b.emptyPlaces()||depth==0){
        return 0;
    }
    sign=(sign=='X') ? 'O':'X'; //zmiana gracza
    maxEval=(sign=='X') ? 10:-10; //ustawienie początkowej wartości zależnie od gracza
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b.size();j++){
            if(b(i,j)==' '){
                b(i,j)=sign;
                eval = minimax(sign, depth-1, alpha, beta, b); //rekurencja, zmiejszamy głębokość o 1
                b(i,j)=' ';
                //W przypadku gracza maksymalizowanego sprawdzamy, czy eval jest większe od maxEval.
                //Jeśli tak, ustawiana jest nowa wartość maxEval
                //Analogicznie postepuje się dla gracza minimalizowanego
                if((sign=='O' && eval>maxEval) || (sign=='X' && eval<maxEval)){
                    maxEval = eval;
                }
                //Alfa-beta cięcia, zależnie od tego, czy gracz jest minimalizowany, czy maksymalizowany
                if(sign=='O'){
                    alpha = MAX(alpha, eval);
                    if(beta<=alpha){
                        break;
                    }
                }else{
                    beta=MIN(beta, eval);
                    if(beta<=alpha){
                        break;
                    }
                }
            }
        }
    }  
    return maxEval; //zwrócenie końcowej wartości
}

void computerMove(Board& b){
    srand(time(NULL));

    int x = INT32_MAX;
    int y = INT32_MAX;

    int eval, maxEval; //zmienne pomocnice
    maxEval=-10; //początkowa wartość
    //W pętli analizuje się każdą możliwa pozycję
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b.size();j++){
            if(b(i,j)==' '){
                b(i,j)='O';
                //wykorzystanie algorytmu minimax o ustalonej głębokości
                //Im większa głębokość, tym większa szansa na optymalne ruchy
                //Niestety duża głębokość zwiększa czas obliczeń
                eval=minimax('O',6,-10, 10, b);
                b(i,j)=' ';
                //Komputer jest graczem maksymalizowanym, więc:
                if(eval>maxEval){
                    maxEval=eval;
                    x=i;
                    y=j;
                }
            }
        }
    }

    if (x == INT32_MAX)
    {
        while(x == INT32_MAX)
        {
            int i = rand() % b.size();
            int j = rand() % b.size();
            if(b(i, j) == ' ')
            {
                x = i;
                y = j;
            }
        }
    }

    cout << b.size() << endl;        
    cout << x << " " << y << endl;
    b(x,y)='O';   //ustawienie znaku na planszy
}
