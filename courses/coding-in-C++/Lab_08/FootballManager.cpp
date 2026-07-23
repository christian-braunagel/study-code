#include "FootballManager.hpp"

#include <iostream>

constexpr int MIN_PROFESSIONAL_AGE = 16;
constexpr int DEFAULT_TRAINING_INTENSITY = 70;

Player::Player(const std::string &name, int age)
    : name(name),
      age(age)
{
}

std::string Player::get_name() const
{
    return name;
}

int Player::get_age() const
{
    return age;
}

void Player::train(int intensity)
{
    if (intensity < 0 || intensity > 100)
    {
        std::cout << "Invalid intensity. Use a value between 0 and 100.\n";
        return;
    }

    std::cout << get_name() << " trains with intensity " << intensity << ".\n";
}

InjuredPlayer::InjuredPlayer(const std::string &name, int age)
    : Player(name, age)
{
}

void InjuredPlayer::train(int intensity)
{
    if (intensity > 30)
    {
        std::cout << "ERROR: Injured players only accept intensity values up to 30.\n";
        return;
    }

    std::cout << get_name() << " performs recovery training with intensity " << intensity << ".\n";
}

void FilePlayerRepository::save(const Player &player)
{
    std::cout << "Saving " << player.get_name() << " to player_file.txt.\n";
}

void EmailNotifier::send(const Player &player, const std::string &message)
{
    std::cout << "Sending email to " << player.get_name() << ": " << message << "\n";
}

void FootballManager::prepare_player(Player &player, const std::string &strategy)
{
    if (player.get_age() < MIN_PROFESSIONAL_AGE)
    {
        std::cout << player.get_name() << " is too young for the professional team.\n";
        return;
    }

    select_strategy(strategy);
    train_player(player, DEFAULT_TRAINING_INTENSITY);
    save_player(player);
    notify_player(player, "Training preparation completed.");
}

void FootballManager::train_player(Player &player, int intensity)
{
    player.train(intensity);
}

void FootballManager::save_player(const Player &player)
{
    repository.save(player);
}

void FootballManager::notify_player(const Player &player, const std::string &message)
{
    notifier.send(player, message);
}

void FootballManager::select_strategy(const std::string &strategy)
{
    if (strategy == "offensive")
    {
        std::cout << "Strategy: offensive pressing.\n";
    }
    else if (strategy == "defensive")
    {
        std::cout << "Strategy: compact defense.\n";
    }
    else
    {
        std::cout << "Strategy: balanced default strategy.\n";
    }
}

int main()
{
    Player player("Alex Striker", 24);
    InjuredPlayer injured_player("Ben Defender", 29);

    FootballManager manager;

    manager.prepare_player(player, "offensive");
    std::cout << "\n";
    manager.prepare_player(injured_player, "defensive");

    return 0;
}
