#include "game.hh"
using namespace std;

int main(){
    startGame(); //rozpoczęcie gry
    do{
        Board board; //utworzenie planszy
        board.clearBoard(); //wypełnienie spacjami
        board.display(); //wyświetlenie pustej planszy
        //Pętla nieskończona. Wyjscie w przypadku wygranej lub remisu
        do{
            //sprawdzenie, czy da się grać:
            if(board.emptyPlaces()){
                playerMove(board); //ruch gracza
                board.display();   //aktualny stan planszy
                //sprawdzenie, czy jest wygrana
                if(board.win('X')){
                    cout<<"Wygrales!!!"<<endl;
                    break;
                }
            }else{
                cout<<"Remis"<<endl;
                break;
            }
            //sprawdzenie, czy da się grać:
            if(board.emptyPlaces()){
                computerMove(board); //ruch komputera
                board.display();     //aktualny stan planszy
                //sprawdzenie, czy jest wygrana
                if(board.win('O')){
                    cout<<"Komputer wygral"<<endl;
                    break;
                }
            }else{
                cout<<"Remis"<<endl;
                break;
            }
        }while(true);
    }while(onceMore()); //dopóki gracz chce grać dalej 
}