#include "Player.h"
#include "Mtmchkin.h"
#include "utilities.h"
#include "Card.h"
#include <iostream>
using std::cout;
using std::endl;

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):m_player(playerName)
{
    this->playerName=playerName;
    this->cardsArray=cardsArray;
    this->m_numOfCards=numOfCards;
    this->m_status=GameStatus::MidGame;
    this->m_index=1;
}

void Mtmchkin::playNextCard()
{
    if(this->m_index > this->m_numOfCards)
    {
        m_index=1;
    }

    Card current_card = this->cardsArray[m_index];
    current_card.printInfo();
    current_card.applyEncounter(m_player);
    if(m_player.isKnockedOut())
    {
        this->m_status=GameStatus::Loss;
        return;
    }
    if(m_player.getLevel()>=10)
    {
        this->m_status=GameStatus::Win;
        return;
    }

    m_index++;
    m_player.printInfo();
}
bool Mtmchkin::isOver() const
{
   if(this->m_status==GameStatus::Win || this->m_status==GameStatus::Loss)
   {
       return true;
   }
   return false;

}
GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_status;
}
