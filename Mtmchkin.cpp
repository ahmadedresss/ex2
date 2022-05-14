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
    this->m_index=0;
}
/*
Mtmchkin::~Mtmchkin()
{
    delete[] this->cardsArray;
}*/



void Mtmchkin::playNextCard()
{
    Card current_card = this->cardsArray[m_index];
    current_card.printInfo();
    current_card.applyEncounter(m_player);
    m_player.printInfo();

    if(m_player.isKnockedOut())
    {
        this->m_status=GameStatus::Loss;
    }
    if(m_player.getLevel()==10)
    {
        this->m_status=GameStatus::Win;
    }

    if(this->m_index > this->m_numOfCards-1)
    {
        m_index=0;
    }
    else
    {
        m_index++;
    }
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
