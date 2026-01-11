#include <iostream>

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "main_functions.h"

using namespace std;

int main() {
    int round_sentinel = 2;
    while (round_sentinel == 2) {
        cout << "Welcome to BlackJackC!" << endl;
        Deck deck;
        round_sentinel = 1;
        setAndGetNumPlayers();
        setPlayerNames();
        deck.setFullDeck(setAndGetNumDecks());
        while (players_in_play && round_sentinel == 1) {
            deck.create(num_of_decks);
            setBets();
            gameSetUp(deck);
            roundOfPlay(deck);
            checkChips();
            round_sentinel = setRoundSentinel();
        }
        Card* deck_ptr = deck.getDeckPointer();
        delete[] deck_ptr;
        delete[] players;
    }
}