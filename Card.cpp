#include "Card.h"


Card::Card(CardType type, const CardStats &stats)
{
    this->m_effect=type;
    this->m_stats = CardStats(stats);
}

void Card::applyEncounter(Player& player) const
{
    if( m_effect == CardType::Battle)
    {
        int attack = player.getAttackStrength();
        if (attack >= m_stats.force)
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);
            return;
        }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
            return;
        }
    }
    if (m_effect == CardType::Heal)
    {
        if (player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
            return;
        }
    }
    if (m_effect == CardType::Buff)
    {
        if (player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
            return;
        }
    }
    if (m_effect == CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
        return;
    }
}

void Card::printInfo() const
{
    if (m_effect == CardType::Battle)
    {
        printBattleCardInfo(m_stats);
        return;
    }
    if (m_effect == CardType::Buff)
    {
        printBuffCardInfo(m_stats);
        return;
    }
    if (m_effect == CardType::Heal)
    {
        printHealCardInfo(m_stats);
        return;
    }
    if (m_effect == CardType::Treasure)
    {
        printTreasureCardInfo(m_stats);
        return;

    }
}
