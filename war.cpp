#include<iostream>
#include "war.h"
using namespace std;





War::War()
{
   // Deck Deck;
   // Deck.shuffle();
   // Deal_Cards(Deck);
   Original_Deck.shuffle();
   Deal_Cards(Original_Deck);



}


War::~War()
{
   // while(!Deck_Player.empty())
   // {
   //     delete Deck_Player.front();
   //     Deck_Player.pop();
   // }

   // while(!Deck_Computer.empty())
   // {
   //     delete Deck_Computer.front();
   //     Deck_Computer.pop();
   // }



   // while(!Deck_Player.empty()) Deck_Player.pop();
   // while(!Deck_Computer.empty()) Deck_Computer.pop();
   // for (Card* c : Original_Deck.Get_All_Cards()) 
   // {
   // delete c;

  // }



    while (!Deck_Player.empty())
    Deck_Player.pop(); // No delete

    while (!Deck_Computer.empty())
    Deck_Computer.pop(); // No delete
}







void War:: Deal_Cards(Deck& Deck)
{
    int i;
    for(int i =0; i < 52; i++)
    {
        Card* card = Deck.draw();

        if (i % 2 == 0)
            Deck_Player.push(card);
        else
            Deck_Computer.push(card);
    }

}


void War::play()
{
    while (!Deck_Player.empty() && !Deck_Computer.empty())
     {
        Play_Round();

    
        if(!Continue_Questionmark())
        {

            cout<<"You forfited!"<<endl;
            cout<<"Human's cards: "<< Deck_Player.size()<<endl;
            cout<<"Computer's cards: "<< Deck_Computer.size()<<endl;
            return ;
        }


        if(Deck_Player.empty())
        {
            cout<<"HUMAN WON!!!"<<endl;
        } else
        {
            cout<<"COMPUTER WON !!! :("<<endl;

        }
    }
}


void War::Play_Round()
{

    if(Deck_Player.empty()||Deck_Computer.empty())
    {
        return;
    }


    Card* Card_Player = Deck_Player.front();
    Deck_Player.pop();
    Card* Card_Computer = Deck_Computer.front();
    Deck_Computer.pop();



    vector<Card*> pile{Card_Player,Card_Computer};
    



    cout<<"You play! "<<endl;
    Card_Player -> print();

    cout<<"Computer plays! ";
    Card_Computer -> print();



    int result = Card_Player -> compareValue(*Card_Computer);

    if(result > 0)
    {
        cout<<"You won this round!"<<endl;
        Deck_Player.push(Card_Player);
        Deck_Player.push(Card_Computer);
    }else if(result < 0)
    {
        cout<<"The computer won this round!"<<endl;
        Deck_Computer.push(Card_Computer);
        Deck_Computer.push(Card_Player);
    }else
    {
        cout<<"WAR!"<<endl;
        War_War(pile);
    }

}



void War::War_War(vector<Card*>& pile)
{
    if (Deck_Player.size() < 2 || Deck_Computer.size() < 2) {
        cout << "Not enough cards for WAR. GAME OVER." << endl;
        return;
    }

    Card* P_Face_Down = Deck_Player.front(); Deck_Player.pop();
    Card* P_Face_Up = Deck_Player.front(); Deck_Player.pop();
    Card* C_Face_Down = Deck_Computer.front(); Deck_Computer.pop();
    Card* C_Face_Up = Deck_Computer.front(); Deck_Computer.pop();

    pile.insert(pile.end(), {P_Face_Down, P_Face_Up, C_Face_Down, C_Face_Up});

    cout << "YOU Play WAR! "; P_Face_Up->print();
    cout << "COMPUTER Play WAR! "; C_Face_Up->print();

    int result = P_Face_Up->compareValue(*C_Face_Up);

    if (result > 0) {
        cout << "You won the WAR!" << endl;
        for (Card* card : pile) Deck_Player.push(card);
    } else if (result < 0) {
        cout << "Computer won the WAR!" << endl;
        for (Card* card : pile) Deck_Computer.push(card);
    } else {
        cout << "WAR CONTINUES!" << endl;
        War_War(pile);  // Recursive war
    }
}




bool War::Continue_Questionmark() 
{
    string input;
    cout << "Continue playing? (y/n): ";
    cin >> input;
    return input == "y" || input == "Y";
}
