#pragma once
#include <iostream>
#include "deck.h"
#include <queue>
using namespace std;





class War
{
    //Constructor and Destructor
    public:
        War();
        ~War();
        
    private:
        Deck Original_Deck;
    
    //PLAY!
    public:
        void play();
    
    protected:
        queue<Card*> Deck_Player;
        queue<Card*> Deck_Computer;

        void Deal_Cards (Deck& deck);
        void Play_Round();
        void War_War(vector<Card*>& pile);
        bool Continue_Questionmark();
    

};