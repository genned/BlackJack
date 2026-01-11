#include <iostream>
#include <string>
#include <vector>

#include "Deck.h"
#include "Card.h"
#include "Player.h"

using namespace std;

string set_names(int card_number) {
  switch (card_number) {
    case 0:
      return "Two";
      break;
    case 1:
      return "Three";
      break;
    case 2:
      return "Four";
      break;
    case 3:
      return "Five";
      break;
    case 4:
      return "Six";
      break;
    case 5:
      return "Seven";
      break;
    case 6:
      return "Eight";
      break;
    case 7:
      return "Nine";
      break;
    case 8:
      return "Ten";
      break;
    case 9:
      return "Jack";
      break;
    case 10:
      return "Queen";
      break;
    case 11:
      return "King";
      break;
    case 12:
      return "Ace";
      break;
    default:
      return "Invalid card number";
      break;
  }
}

string set_suit(int batch_number) {
  switch (batch_number) {
    case 0:
      return "Spades";
      break;
    case 1:
      return "Hearts";
      break;
    case 2:
      return "Diamonds";
      break;
    case 3:
      return "Clubs";
      break;
   default:
     return "Invalid batch number";
     break;

  }
}

void Deck::setFullDeck(Card main_deck[]) {
  cards_ptr = &main_deck[0];
}

void Deck::create(int num_of_decks) {
  int count_main = 0;
  decks_used = num_of_decks;
  num_of_cards = 52 * decks_used;
  cards_dealt = 0;
  for (int count_decks = 0; count_decks < num_of_decks; count_decks++) {
    for (int count_outer = 0; count_outer < suits; count_outer++) {
      for (int count_inner = 0; count_inner < cards_per_suit; count_inner++) {
        cards_ptr[count_main].set_card_value((count_inner + 1 < 10)?count_inner + 2:(count_inner + 1 == 13)?11:10);
        cards_ptr[count_main].set_card_name(set_names(count_inner));
        cards_ptr[count_main].set_card_suit(set_suit(count_outer));
        count_main++;
      }
    }
  }
  usable_deck.clear();
  for (int count = 0; count < count_main; count++) {
    usable_deck.push_back(cards_ptr[count]);
  }
}

Card Deck::dealCard(int card_num) {
  Card temp_card = usable_deck[card_num];
  int temp_ptr_size = (num_of_cards) - 1;
  for (int count = 0; count < temp_ptr_size; count++) {
    if (count == card_num) {
      Card swap_card = usable_deck[count];
      usable_deck[count] = usable_deck[temp_ptr_size];
      usable_deck[temp_ptr_size] = swap_card;
      usable_deck.pop_back();
    }
  }
  cards_dealt++;
  num_of_cards = num_of_cards - 1;
  return temp_card;
}

Card* Deck::getDeckPointer() {
  return cards_ptr;
}

int Deck::getDeckSize() {
  return num_of_cards;
}
