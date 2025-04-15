#pragma once

#include <vector>
#include <stack>
using namespace std;

#include "card.h"

class Deck
{
public:
    Deck();
    ~Deck();
    

public:
    void shuffle();
    Card* draw();
    vector<Card*>& Get_All_Cards();

protected:
    std::vector<Card*> full_deck;
    std::stack<Card*> draw_deck;
};