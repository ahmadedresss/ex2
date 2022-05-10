#include "Player.h"
#include "utilities.h"
#include <iostream>
using std::cout;
using std::endl;

#define DE_LEVEL 1
#define FORCE 5
#define DE_HP 100


Player::Player(const char* name ,int max_hp , int force)
{
    m_name=name;
    m_maxHP=max_hp;
    m_force=force;
    m_level=DE_LEVEL;
    m_HP=max_hp;
    m_coins=0;
}

void Player::printInfo ()const
{
    printPlayerInfo(m_name, m_level, m_force, m_maxHP, m_coins);
}

void Player::levelUp()
{
    m_level+=1;
}

int Player::getLevel()const
{
    return m_level;
}

void Player::buff(int add_force)
{
    m_force+=add_force;
}

void Player::heal(int add_hp)
{
    m_HP+=add_hp;
    if (m_HP > DE_HP)
    {
        m_HP=DE_HP;
    }
}

void Player::damage(int damage_par)
{
    m_HP-=damage_par;
    if (m_HP < 0)
    {
        m_HP=0;
    }
}

bool Player::isKnockedOut() const
{
    if (m_HP==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Player::addCoins(int addedCoins)
{
    m_coins += addedCoins;
}

bool Player::pay(int coinsToPay)
{
    if(coinsToPay>0)
    {
        if(m_coins - coinsToPay <0)
        {
            return false;
        }
        else
        {
            m_coins -= coinsToPay;
            return true;
        }
    }
    return true;
}

int Player::getAttackStrength() const
{
    return m_force + m_level;
}
