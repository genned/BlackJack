#ifndef TEST_H
#define TEST_H

#include <string>

using namespace std;

class Card {
    int card_value = 0;
    string card_name = " ";
    string card_suit = " ";
    public:
        void set_card_value(int card_value);
        int get_card_value();
        void set_card_name(string card_name);
        string get_card_name();
        void set_card_suit(string card_suit);
        string get_card_suit();
        string card_info();
};

#endif //TEST_H
