#include "FootballManager_refactored.hpp"

#include <iostream>

constexpr int MIN_PROFESSIONAL_AGE = 16;
constexpr int MIN_TRAINING_INTENSITY = 0;
constexpr int MAX_TRAINING_INTENSITY = 100;
constexpr int MAX_RECOVERY_INTENSITY = 30;

Player::Player(const std::string &name, int age, PlayerStatus status)
    : name(name),
      age(age),
      status(status)
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

PlayerStatus Player::get_status() const
{
    return status;
}

bool Player::is_available_for_match() const
{
    return status == PlayerStatus::Available;
}

void StandardTrainingPlan::train(Player &player, int intensity) const
{
    if (intensity < MIN_TRAINING_INTENSITY || intensity > MAX_TRAINING_INTENSITY)
    {
        std::cout << "Invalid training intensity.\n";
        return;
    }

    std::cout << player.get_name()
              << " performs standard team training with intensity "
              << intensity
              << ".\n";
}

void RecoveryTrainingPlan::train(Player &player, int intensity) const
{
    if (intensity < MIN_TRAINING_INTENSITY || intensity > MAX_RECOVERY_INTENSITY)
    {
        std::cout << "Invalid recovery intensity. Recovery training allows values from 0 to 30.\n";
        return;
    }

    std::cout << player.get_name()
              << " performs recovery training with intensity "
              << intensity
              << ".\n";
}

void OffensiveStrategy::apply() const
{
    std::cout << "Using offensive strategy.\n";
    std::cout << "Focus: high pressing and many attackers.\n";
}

void DefensiveStrategy::apply() const
{
    std::cout << "Using defensive strategy.\n";
    std::cout << "Focus: compact defense and counter attacks.\n";
}

MySQLPlayerRepository::MySQLPlayerRepository()
{
    connect();
}

void MySQLPlayerRepository::connect()
{
    std::cout << "Connecting to MySQL player database...\n";
}

void MySQLPlayerRepository::save(const Player &player)
{
    std::cout << "Saving player " << player.get_name() << " to MySQL database.\n";
}

void EmailMessageService::send_message(const Player &player, const std::string &message)
{
    std::cout << "Sending email to " << player.get_name() << ": " << message << "\n";
}

void ConsoleReportPrinter::print_report(const Player &player)
{
    std::cout << "Sponsor Report\n";
    std::cout << "Player: " << player.get_name() << "\n";
    std::cout << "Age: " << player.get_age() << "\n";
}

FootballManager::FootballManager(
    PlayerRepository &repository,
    MessageService &message_service,
    ReportPrinter &report_printer)
    : repository(repository),
      message_service(message_service),
      report_printer(report_printer)
{
}

void FootballManager::manage_player(
    Player &player,
    const TrainingPlan &training_plan,
    const MatchStrategy &match_strategy,
    int training_intensity)
{
    std::cout << "Managing player " << player.get_name() << ".\n";

    if (player.get_age() < MIN_PROFESSIONAL_AGE)
    {
        std::cout << "Player is too young for the professional team.\n";
        return;
    }

    if (training_intensity < training_plan.get_min_intensity() ||
        training_intensity > training_plan.get_max_intensity())
    {
        std::cout << "Invalid intensity for this training plan.\n";
        return;
    }

    training_plan.train(player, training_intensity);
    match_strategy.apply();

    if (player.is_available_for_match())
    {
        std::cout << player.get_name() << " is playing a match.\n";
    }
    else
    {
        std::cout << player.get_name() << " is not available for the match.\n";
    }

    repository.save(player);
    message_service.send_message(player, "Training and match preparation completed.");
    report_printer.print_report(player);

    managed_players.push_back(&player);
}

int main()
{
    Player player("Alex Striker", 24, PlayerStatus::Available);
    Player injured_player("Ben Defender", 29, PlayerStatus::Injured);

    MySQLPlayerRepository repository;
    EmailMessageService message_service;
    ConsoleReportPrinter report_printer;

    StandardTrainingPlan standard_training;
    RecoveryTrainingPlan recovery_training;
    OffensiveStrategy offensive_strategy;
    DefensiveStrategy defensive_strategy;

    FootballManager manager(repository, message_service, report_printer);

    manager.manage_player(player, standard_training, offensive_strategy, 70);

    std::cout << "\n";

    manager.manage_player(injured_player, recovery_training, defensive_strategy, 20);

    return 0;
}
