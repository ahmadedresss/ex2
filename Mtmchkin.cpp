
#include "Player.h"
#include "Mtmchkin.h"
#include "utilities.h"
#include "Card.h"
#include <iostream>
using std::cout;
using std::endl;

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):m_player(playerName)
{
    this->m_numOfCards=numOfCards;
    this->m_status=GameStatus::MidGame;
    this->m_index=0;
     m_temp = new Card[numOfCards];
    for (int i = 0; i < numOfCards; i++)
    {
        m_temp[i] = cardsArray[i];
    }
}


Mtmchkin& Mtmchkin::operator=(const Mtmchkin& copy)
{
    delete[] m_temp;
    m_temp=new Card[copy.m_numOfCards];
    for (int i = 0; i < copy.m_numOfCards; i++)
    {
        m_temp[i] = cardsArray[i];
    }
    this->m_numOfCards=copy.m_numOfCards;
    this->m_status=copy.m_status;
    this->m_index=copy.m_index;
    this->m_player=copy.m_player;
    return*this;
}

Mtmchkin::Mtmchkin(const Mtmchkin& copy): m_player(copy.m_player)
{
    this->m_numOfCards=copy.m_numOfCards;
    this->m_status=copy.m_status;
    this->m_index=copy.m_index;
    m_temp=new Card[copy.m_numOfCards];
    for (int i = 0; i < copy.m_numOfCards; i++)
    {
        m_temp[i] = cardsArray[i];
    }
}


Mtmchkin::~Mtmchkin()
{
    delete[] m_temp;
}

void Mtmchkin::playNextCard()
{
    Card current_card=m_temp[m_index];
    current_card.printInfo();
    current_card.applyEncounter(m_player);


    if(m_player.isKnockedOut())
    {
        this->m_status=GameStatus::Loss;
    }
    if(m_player.getLevel()==10)
    {
        this->m_status=GameStatus::Win;
    }

    m_player.printInfo();

    if(++m_index == this->m_numOfCards)
    {
        m_index=0;
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
