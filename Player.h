#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

#include <string>
#include <vector>


class Deck;
using namespace std;

class Player {
    int chips = 0;
    int hand_value = 0;
    int cards_in_hand = 2;
    string player_name;
    vector<Card> hand;
    int round_bet = 0;

    public:
        void drawCard(Deck &deck);
        void setPlayerName(string name_of_player);
        void setChips(int num_chips);
        int getChips();
        void setHandValue();
        string getPlayerName();
        int getHandValue();
        Card getCard(int index_of_card);
        bool hasChips();
        vector<Card> getHand();
        void setRoundBet(int bet);
        int getRoundBet();
        void clearHand();
};

#endif //PLAYER_H
