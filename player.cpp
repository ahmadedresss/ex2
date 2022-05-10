#include "Player.h"


#define DE_LEVEL 1
#define FORCE 5
#define DE_HP 100


player::player(const char* name ,int max_hp , int force)
{
    m_name=name;
    m_maxHP=max_hp;
    m_force=force;
    m_level=DE_LEVEL;
    m_HP=max_hp;
    m_coins=0;
};

void player::print_info ()const
{
    printPlayerInfo(m_name, m_level, m_force, m_maxHP, m_coins);

}

void player::levelUp()
{
   m_level+=1;
}

int player::getLevel()const
{
   return m_level;
}

void player::buff(int add_force)
{
    m_force+=add_force;
}

void player::heal(int add_hp)
{
    m_HP+=add_hp;
    if (m_HP > DE_HP)
    {
        m_HP=DE_HP;
    }
}

void player::damage(int damage_par)
{
    m_HP-=damage_par;
    if (m_HP < 0)
    {
        m_HP=0;
    }
}

bool player::isKnockedOut() const
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

bool player::pay(int coinsToPay)
{
    if(coinsToPay>0)
    {
        if(m_coins - coinsToPay <0)
        {
            cout<<"Not enough coins"<<endl;
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

int Player::getAttackStrength()
{
    return m_force + m_level;
}
 
