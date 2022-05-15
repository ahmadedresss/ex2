//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>

static const int INDEX_OF_FIRST_CARD = 0;
/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);


    /*
     * C'tor of Mtmchkin class:
     * @param m - A reference of an existing Mtmchkin .
     *
     * @result
     *      A coppied instance of Mtmchkin
    */
    Mtmchkin(const Mtmchkin& m);


    /*
     * D'tor of Mtmchkin class
     *
     * @return
     *      Deletes this instance of Mtmchkin.
    */
    ~Mtmchkin();


    /*
     * Assignment operator
     *
     * @param p - The Mtmchkin to assign from.
     * @return
     *      default
    */
    Mtmchkin& operator=(Mtmchkin& p);


    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;


private:

    GameStatus m_gameStatus;
    int m_currentCard;
    int m_amountOfCards;
    Player m_player;
    Card* m_cardsArr;

    /*
     * Copy the cardsArray:
     *
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     *
     * @return
     *      A coppied array of the cardsArray.
    */
    Card* copyCardsArray(const Card* cardsArray, int numOfCards);

};


#endif //EX2_GAME_H
