#include "Player.h"
#include "utilities.h"
#include <iostream>
using std::cout;
using std::endl;

#define DE_LEVEL 1
#define FORCE 5
#define DE_HP 100


Player::Player(const char* name ,int max_hp , int force):m_name(name),m_level(DE_LEVEL)
                                                        ,m_HP(max_hp),m_coins(0)
{
    if(max_hp<=0)
    {
        m_maxHP=m_HP=DE_HP;
    }
    else
    {
        m_maxHP=m_HP=max_hp;
    }
    if(force<=0)
        m_force=FORCE;
    else
        m_force=force;
}

void Player::printInfo ()const
{
    printPlayerInfo(m_name, m_level, m_force, m_HP, m_coins);
}

void Player::levelUp()
{
    if(m_level>=10)
    {
        return;
    }
    m_level++;
}

int Player::getLevel()const
{
    return m_level;
}

void Player::buff(int add_force)
{
    if(add_force<=0)
    {
        return;
    }
    m_force+=add_force;
}

void Player::heal(int add_hp)
{
    if(add_hp<=0)
    {
    return;
    }
    if (m_HP +add_hp>= m_maxHP)
    {
        m_HP=m_maxHP;
        return;
    }
    m_HP+=add_hp;

}

void Player::damage(int damage_par)
{
    if(damage_par<=0)
    {
        return;
    }
    if(m_HP<damage_par)
    {
        m_HP=0;

    }
    else
        m_HP-=damage_par;

    if(m_HP<0)
        m_HP=0;

}

bool Player::isKnockedOut() const
{
    if (m_HP<=0)
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
    if(addedCoins<=0)
    {
        return;
    }
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

        m_coins -= coinsToPay;
        return true;
    }
    return true;
}

int Player::getAttackStrength() const
{
    return m_force + m_level;
}
 
