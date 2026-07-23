#include "game_character_system.hpp"
#include <iostream>

/* ================= Weapon ================= */

Weapon::Weapon(const std::string &name, unsigned int damage)
    : name(name), damage(damage)
{
}

std::string Weapon::getName() const
{
    return name;
}

unsigned int Weapon::getDmg() const
{
    return damage;
}

/* ================= Inventory ================= */

Inventory::Inventory()
    : item_count(0)
{
}

bool Inventory::isEmpty() const
{
    return (item_count == 0);
}

bool Inventory::isFull() const
{
    return (item_count >= MAX_SLOTS);
}

bool Inventory::addItem(const std::string &item)
{
    if (isFull())
    {
        return false;
    }

    items[item_count] = item;
    item_count++;
    return true;
}

bool Inventory::removeLastItem(std::string &item)
{
    if (isEmpty())
    {
        return false;
    }

    item_count--;
    item = items[item_count];
    return true;
}

/* ================= Character ================= */

const unsigned int Character::levelLimits[Character::MAX_LEVEL - 1] =
    {
        100, 250, 450, 700, 1000, 1400, 1900, 2500, 3200};

Character::Character(
    const std::string &name,
    unsigned int health_points,
    unsigned int level,
    unsigned int experience_points)
    : health_points(DEFAULT_HEALTH_POINTS),
      name(name),
      level(DEFAULT_LEVEL),
      experience_points(DEFAULT_EXPERIENCE_POINTS),
      weapon(nullptr)
{
    /* Validate health points */
    if (health_points > 0U)
    {
        this->health_points = health_points;
    }

    /* Validate level */
    if ((level >= 1U) && (level <= MAX_LEVEL))
    {
        this->level = level;
    }

    /* Validate experience points */
    if (experience_points < levelLimits[MAX_LEVEL - 2])
    {
        this->experience_points = experience_points;
    }
}

unsigned int Character::getHealthPoints() const
{
    return health_points;
}

unsigned int Character::getLevel() const
{
    return level;
}

Inventory &Character::getInventory()
{
    return inventory;
}

Character &Character::damageTaken(unsigned int dmg)
{
    if (dmg >= health_points)
    {
        health_points = 0U;
    }
    else
    {
        health_points -= dmg;
    }

    return *this;
}

Character &Character::earnExperience(unsigned int exp)
{
    experience_points += exp;

    while ((level < MAX_LEVEL) &&
           (experience_points >= levelLimits[level - 1U]))
    {
        levelUp();
    }

    return *this;
}

void Character::levelUp()
{
    if (level < MAX_LEVEL)
    {
        level++;
    }
}

/* ================= Mage ================= */

Mage::Mage(
    const std::string &name,
    unsigned int health_points,
    unsigned int level,
    unsigned int experience_points)
    : Character(name, health_points, level, experience_points),
      magic_points(100U)
{
}

Mage &Mage::regenerateMagic(unsigned int magic_points)
{
    this->magic_points += magic_points;
    return *this;
}

Mage &Mage::displayStatus() const
{
    std::cout << "Mage: " << name
              << " HP: " << getHealthPoints()
              << " MP: " << magic_points
              << " Level: " << level << std::endl;

    return const_cast<Mage &>(*this);
}

/* ================= Warrior ================= */

Warrior::Warrior(
    const std::string &name,
    unsigned int health_points,
    unsigned int level,
    unsigned int experience_points)
    : Character(name, health_points, level, experience_points),
      ws_points(100U)
{
}

Warrior &Warrior::regenerateWSPoints(unsigned int ws_points)
{
    this->ws_points += ws_points;
    return *this;
}

Warrior &Warrior::displayStatus() const
{
    std::cout << "Warrior: " << name
              << " HP: " << getHealthPoints()
              << " WS: " << ws_points
              << " Level: " << level << std::endl;

    return const_cast<Warrior &>(*this);
}

/* ================= Healer ================= */

Healer::Healer(
    const std::string &name,
    unsigned int health_points,
    unsigned int level,
    unsigned int experience_points)
    : Mage(name, health_points, level, experience_points)
{
}

Healer &Healer::heal(unsigned int health_points, Character &target)
{
    target.health_points += health_points;
    return *this;
}

/* ================= Thief ================= */

Thief::Thief(
    const std::string &name,
    unsigned int health_points,
    unsigned int level,
    unsigned int experience_points)
    : Warrior(name, health_points, level, experience_points)
{
}

Thief &Thief::steal(Character &target)
{
    std::string item;

    if (target.getInventory().removeLastItem(item))
    {
        this->getInventory().addItem(item);
    }

    return *this;
}