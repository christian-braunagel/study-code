#ifndef FOOTBALL_MANAGER_HPP
#define FOOTBALL_MANAGER_HPP

#include <string>
#include <vector>

/**
 * @brief Represents the current medical availability of a player.
 */
enum class PlayerStatus
{
    Available,
    Injured
};

/**
 * @brief Represents a football player as a simple domain object.
 *
 * This class no longer contains training or match behavior. It only stores
 * player-related data. This avoids an LSP problem where an injured player
 * would inherit from Player but would reject calls that normal Player objects
 * accept.
 */
class Player
{
private:
    std::string name;
    int age;
    PlayerStatus status;

public:
    Player(const std::string &name, int age, PlayerStatus status);

    std::string get_name() const;
    int get_age() const;
    PlayerStatus get_status() const;

    bool is_available_for_match() const;
};

/**
 * @brief Abstraction for training behavior.
 */
class TrainingPlan
{
public:
    virtual ~TrainingPlan() = default;
    virtual int get_min_intensity() const = 0;
    virtual int get_max_intensity() const = 0;
    virtual void train(Player &player, int intensity) const = 0;
};

class StandardTrainingPlan : public TrainingPlan
{
public:
    void train(Player &player, int intensity) const override;
    int get_min_intensity() const override { return 0; }
    int get_max_intensity() const override { return 100; }
};

class RecoveryTrainingPlan : public TrainingPlan
{
public:
    void train(Player &player, int intensity) const override;
    int get_min_intensity() const override { return 0; }
    int get_max_intensity() const override { return 30; }
};

/**
 * @brief Abstraction for match strategy behavior.
 */
class MatchStrategy
{
public:
    virtual ~MatchStrategy() = default;

    virtual void apply() const = 0;
};

class OffensiveStrategy : public MatchStrategy
{
public:
    void apply() const override;
};

class DefensiveStrategy : public MatchStrategy
{
public:
    void apply() const override;
};

/**
 * @brief Abstraction for player persistence.
 */
class PlayerRepository
{
public:
    virtual ~PlayerRepository() = default;

    virtual void save(const Player &player) = 0;
};

/**
 * @brief Abstraction for sending messages to players.
 */
class MessageService
{
public:
    virtual ~MessageService() = default;

    virtual void send_message(const Player &player, const std::string &message) = 0;
};

/**
 * @brief Abstraction for report printing.
 */
class ReportPrinter
{
public:
    virtual ~ReportPrinter() = default;

    virtual void print_report(const Player &player) = 0;
};

class MySQLPlayerRepository : public PlayerRepository
{
private:
    void connect();

public:
    MySQLPlayerRepository();

    void save(const Player &player) override;
};

class EmailMessageService : public MessageService
{
public:
    void send_message(const Player &player, const std::string &message) override;
};

class ConsoleReportPrinter : public ReportPrinter
{
public:
    void print_report(const Player &player) override;
};

/**
 * @brief Coordinates football management workflows.
 *
 * The manager depends on abstractions instead of concrete infrastructure
 * classes. Training, strategy, persistence, messaging, reporting and payment
 * are delegated to separate services.
 */
class FootballManager
{
private:
    PlayerRepository &repository;
    MessageService &message_service;
    ReportPrinter &report_printer;
    std::vector<Player *> managed_players;

public:
    FootballManager(
        PlayerRepository &repository,
        MessageService &message_service,
        ReportPrinter &report_printer);

    void manage_player(
        Player &player,
        const TrainingPlan &training_plan,
        const MatchStrategy &match_strategy,
        int training_intensity);
};

#endif
