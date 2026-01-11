#include <iostream>
#include <string>

#include "Card.h"

using namespace std;

void Card::set_card_value(int card_value_passed){
    card_value = card_value_passed;
}

int Card::get_card_value(){
    return card_value;
}

void Card::set_card_name(string card_name_passed){
  card_name = card_name_passed;
}

string Card::get_card_name(){
    return card_name;
}

void Card::set_card_suit(string card_suit_passed){
  card_suit = card_suit_passed;
}

string Card::get_card_suit(){
    return card_suit;
}

string Card::card_info() {
  string full_card;
  full_card = "" + get_card_name() + " of " + get_card_suit();
  return full_card;
}