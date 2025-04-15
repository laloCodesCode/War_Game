#include<iostream>
#include "war.h"
using namespace std;





War::War()
{
    Deck Deck;
    Deck.shuffle();
    Deal_Cards(Deck);
}


War::~War()
{
    while(!Deck_Player.empty())
    {
        delete Deck_Player.front();
        Deck_Player.pop();
    }

    while(!Deck_Computer.empty())
    {
        delete Deck_Computer.front();
        Deck_Computer.pop();
    }
}








void War:: Deal_Cards(Deck& Deck)
{
    int i;
    for(int i =0; i < 52; i++){}
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



void War:: War_War(vector<Card*>&pile)
{
    while (true) 
    {
        if (Deck_Player.size() < 2 || Deck_Computer.size() < 2) 
        {
            cout << "Not enough cards for WAR. GAME OVER."<<endl;
        }
    }



    Card* P_Face_Down = Deck_Player.front(); Deck_Player.pop();
    Card* P_Face_Up = Deck_Player.front();Deck_Player.pop();
    Card* C_Face_Down = Deck_Computer.front(); Deck_Computer.pop();
    Card* C_Face_Up = Deck_Computer.front(); Deck_Computer.pop();

    pile.insert(pile.end(), {P_Face_Down, P_Face_Up, C_Face_Down, C_Face_Up});


    cout<<"YOU Play WAR! "<<endl;
    P_Face_Down -> print();

    cout<<"COMPUTER Play WAR! "<<endl;
    C_Face_Down -> print();


    int result = P_Face_Up->compareValue(*C_Face_Up);


    if(result > 0)
    {
        cout<<"You won this round!"<<endl;
        for (Card* card : pile) Deck_Player.push(card);
        return;
    }else if(result < 0)
    {
        cout<<"The computer won this round!"<<endl;
        for (Card* card : pile) Deck_Computer.push(card);
        return;
    }else
    {
        cout<<"WAR CONTINUES!"<<endl;
        return;
    }

}


bool War::Continue_Questionmark() 
{
    string input;
    cout << "Continue playing? (y/n): ";
    cin >> input;
    return input == "y" || input == "n";
}
