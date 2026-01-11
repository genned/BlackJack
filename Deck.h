#ifndef DECK_H
#define DECK_H

#include <vector>

#include "Card.h"
#include "Player.h"

using namespace std;

class Deck {
    int decks_used = 0;
    int num_of_cards = 0;
    int const cards_per_suit = 13;
    int const suits = 4;
    int cards_dealt = 0;
    Card* cards_ptr;
    vector<Card> usable_deck;

    public:
        void create(int num_of_decks);
        Card dealCard(int card_num);
        Card* getDeckPointer();
        int getDeckSize();
        void setDeckSize();
        int getCardsDealt();
        void setFullDeck(Card main_deck[]);
};

#endif //DECK_H
