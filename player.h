

class Player{
private:
        char * m_name;
        int m_level; //the level of the player
        int m_force; // the force of the player
        int m_maxHP;//maxHP of the player
        int m_HP; // the  Health points-HP of the player
        int m_coins;//the  coins of the player
       public:

        player(const char* name ,int max_hp , int force);
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
        void damage(int hp);

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


}
