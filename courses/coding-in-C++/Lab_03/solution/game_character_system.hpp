#ifndef GAME_CHARACTER_SYSTEM_HPP
#define GAME_CHARACTER_SYSTEM_HPP

#include <string>

/**
 * @brief Represents a weapon used by a character.
 */
class Weapon
{
private:
    std::string name;
    unsigned int damage;

public:
    /**
     * @brief Creates a weapon.
     *
     * @param[in] name    Name of the weapon
     * @param[in] damage  Damage value
     */
    Weapon(const std::string &name, unsigned int damage);

    /**
     * @brief Returns the weapon name.
     *
     * @return Weapon name
     */
    std::string getName() const;

    /**
     * @brief Returns the damage value.
     *
     * @return Damage value
     */
    unsigned int getDmg() const;
};

/**
 * @brief Represents an inventory with limited slots.
 */
class Inventory
{
private:
    static constexpr unsigned int MAX_SLOTS = 10;

    std::string items[MAX_SLOTS];
    unsigned int item_count;

public:
    /**
     * @brief Creates an empty inventory.
     */
    Inventory();

    /**
     * @brief Checks if inventory is empty.
     *
     * @return true if empty, otherwise false
     */
    bool isEmpty() const;

    /**
     * @brief Checks if inventory is full.
     *
     * @return true if full, otherwise false
     */
    bool isFull() const;

    /**
     * @brief Adds an item to the inventory.
     *
     * @param[in] item  Item name
     * @return true if added, otherwise false
     */
    bool addItem(const std::string &item);

    /**
     * @brief Removes the last item.
     *
     * @param[out] item  Removed item
     * @return true if removed, otherwise false
     */
    bool removeLastItem(std::string &item);
};

/**
 * @brief Base class for all characters.
 */
class Character
{
private:
    static constexpr unsigned int DEFAULT_HEALTH_POINTS = 100;
    static constexpr unsigned int DEFAULT_LEVEL = 1;
    static constexpr unsigned int DEFAULT_EXPERIENCE_POINTS = 0;

    unsigned int health_points;

    friend class Healer;

protected:
    std::string name;
    unsigned int level;
    unsigned int experience_points;

    static constexpr unsigned int MAX_LEVEL = 10;
    static const unsigned int levelLimits[MAX_LEVEL - 1];

    Inventory inventory;
    Weapon *weapon;

public:
    /**
     * @brief Creates a character with validated values.
     *
     * Invalid values are replaced with default values.
     *
     * @param[in] name               Character name
     * @param[in] health_points      Initial health points
     * @param[in] level              Initial level
     * @param[in] experience_points  Initial experience points
     */
    Character(
        const std::string &name,
        unsigned int health_points,
        unsigned int level,
        unsigned int experience_points);

    /**
     * @brief Returns current health points.
     *
     * @return Health points
     */
    unsigned int getHealthPoints() const;

    /**
     * @brief Returns current level.
     *
     * @return Level
     */
    unsigned int getLevel() const;

    /**
     * @brief Returns the inventory.
     *
     * @return Reference to inventory
     */
    Inventory &getInventory();

    /**
     * @brief Applies damage to the character.
     *
     * @param[in] dmg  Damage value
     * @return Reference to character
     */
    Character &damageTaken(unsigned int dmg);

    /**
     * @brief Adds experience and performs level-up if necessary.
     *
     * @param[in] exp  Experience points
     * @return Reference to character
     */
    Character &earnExperience(unsigned int exp);

    /**
     * @brief Increases level if possible.
     */
    void levelUp();
};

/**
 * @brief Mage class.
 */
class Mage : public Character
{
protected:
    unsigned int magic_points;

public:
    /**
     * @brief Creates a mage.
     *
     * @param[in] name               Name
     * @param[in] health_points      Health
     * @param[in] level              Level
     * @param[in] experience_points  Experience
     */
    Mage(
        const std::string &name,
        unsigned int health_points,
        unsigned int level,
        unsigned int experience_points);

    /**
     * @brief Regenerates magic points.
     *
     * @param[in] magic_points  Points to add
     * @return Reference to mage
     */
    Mage &regenerateMagic(unsigned int magic_points);

    /**
     * @brief Displays current status.
     *
     * @return Reference to mage
     */
    Mage &displayStatus() const;
};

/**
 * @brief Warrior class.
 */
class Warrior : public Character
{
protected:
    unsigned int ws_points;

public:
    /**
     * @brief Creates a warrior.
     *
     * @param[in] name               Name
     * @param[in] health_points      Health
     * @param[in] level              Level
     * @param[in] experience_points  Experience
     */
    Warrior(
        const std::string &name,
        unsigned int health_points,
        unsigned int level,
        unsigned int experience_points);

    /**
     * @brief Regenerates weapon skill points.
     *
     * @param[in] ws_points  Points to add
     * @return Reference to warrior
     */
    Warrior &regenerateWSPoints(unsigned int ws_points);

    /**
     * @brief Displays current status.
     *
     * @return Reference to warrior
     */
    Warrior &displayStatus() const;
};

/**
 * @brief Healer class (friend of Character).
 */
class Healer : public Mage
{
public:
    /**
     * @brief Creates a healer.
     *
     * @param[in] name               Name
     * @param[in] health_points      Health
     * @param[in] level              Level
     * @param[in] experience_points  Experience
     */
    Healer(
        const std::string &name,
        unsigned int health_points,
        unsigned int level,
        unsigned int experience_points);

    /**
     * @brief Heals another character.
     *
     * @param[in] health_points  Healing amount
     * @param[in,out] target     Target character
     * @return Reference to healer
     */
    Healer &heal(unsigned int health_points, Character &target);
};

/**
 * @brief Thief class.
 */
class Thief : public Warrior
{
public:
    /**
     * @brief Creates a thief.
     *
     * @param[in] name               Name
     * @param[in] health_points      Health
     * @param[in] level              Level
     * @param[in] experience_points  Experience
     */
    Thief(
        const std::string &name,
        unsigned int health_points,
        unsigned int level,
        unsigned int experience_points);

    /**
     * @brief Steals an item from another character.
     *
     * @param[in,out] target  Target character
     * @return Reference to thief
     */
    Thief &steal(Character &target);
};

#endif