#include <iostream>
#include <string>
#include <vector>
#include <random>

#include "Deck.h"
#include "Card.h"
#include "Player.h"

using namespace std;
//spaghetti code moment, reference Deck::getDeckSize/dealCard
void Player::drawCard(Deck &deck) {
  srand(time(NULL));
    int pull_card_value = rand() % (deck.getDeckSize() + 1 - 0) + 0;
    hand.push_back(deck.dealCard(pull_card_value));
}

void Player::setPlayerName(string name_of_player) {
  player_name = name_of_player;
}

void Player::setChips(int num_chips) {
  chips = num_chips;
}

int Player::getChips() {
  return chips;
}

void Player::setHandValue() {
  hand_value = 0;
  for (int count = 0; count < hand.size(); count++) {
    if (hand[count].get_card_value() == 11 && hand_value > 10){
      hand_value = hand_value + 1;
    }
    else {
      hand_value = hand_value + hand[count].get_card_value();
    }
  }
}

string Player::getPlayerName() {
  return player_name;
}

int Player::getHandValue() {
  return hand_value;
}

Card Player::getCard(int index_of_card) {
  return hand[index_of_card];
}

bool Player::hasChips() {
  if (chips < 0) {
    return false;
  }
  else {
    return true;
  }
}

vector<Card> Player::getHand() {
  return hand;
}

void Player::setRoundBet(int bet) {
  round_bet = bet;
  chips = chips - bet;
}

int Player::getRoundBet() {
  return round_bet;
}

void Player::clearHand() {
  hand.clear();
}