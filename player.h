#ifndef Player_h
#define Player_h

#define DE_LEVEL 1
#define FORCE 5
#define DE_HP 100

class Player{

public:

    Player(const char* name ,int max_hp=DE_HP , int force=FORCE);
    /*
     *  the constructor
     */

    void addCoins(int addedCoins);

    /*
     * function adds coins to the current coins
     */
    bool pay(int coinsToPay);

    /*
     * returns true if the coins is enough else it returns false
     */
    void heal(int hp);

    /*
     * increase the HP in the inserted amount till the maxHP.
     */
    void damage(int damage_par);

    /*
     * decreases the HP in the inserted amount .
     */
    void buff(int add_force);

    /*
     * Increases the player's force level by the added amount.
     */
    void levelUp();

    /*
     * Increases the receiver's (player) level by the one level.
     */
    int getLevel()const ;

    /*
     * Returns the level of the player.
     *
     */
    int getAttackStrength() const;

    /*
     * the function returns the player's force + level(attack strength)
     */
    bool isKnockedOut() const;

    /*
     * here we check if the player is out of health power
    */
    void printInfo() const;

    /*
     * Prints the player info:
    */

private:
    const char * m_name;
    int m_level; //the level of the player
    int m_force; // the force of the player
    int m_maxHP;//maxHP of the player
    int m_HP; // the  Health points-HP of the player
    int m_coins;//the  coins of the player

};
#endif
