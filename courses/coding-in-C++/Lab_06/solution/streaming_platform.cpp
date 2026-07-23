/**
 * @file streaming_platform_part3.cpp
 * @brief Demonstrates std::unique_ptr, std::shared_ptr and inheritance.
 *
 * This program implements a simple streaming platform with rooms and devices.
 *
 * Regular devices belong exclusively to one room and are managed by
 * std::unique_ptr.
 *
 * Shared devices inherit from Device, add network functionality and may be
 * shared between multiple rooms using std::shared_ptr.
 */

#include <iostream>
#include <list>
#include <memory>
#include <string>

/**
 * @brief Represents a general media device.
 */
class Device
{
private:
    std::string name;
    std::string type;
    bool power_status;

public:
    /**
     * @brief Constructs a new Device object.
     *
     * @param device_name Name of the device.
     * @param device_type Type of the device.
     * @param is_powered_on Initial power status.
     */
    Device(const std::string &device_name,
           const std::string &device_type,
           bool is_powered_on = false)
        : name(device_name),
          type(device_type),
          power_status(is_powered_on)
    {
    }

    /**
     * @brief Returns the device name.
     *
     * @return Constant reference to the device name.
     */
    const std::string &get_name() const
    {
        return name;
    }

    /**
     * @brief Turns the device on.
     */
    void turn_on()
    {
        power_status = true;
    }

    /**
     * @brief Turns the device off.
     */
    void turn_off()
    {
        power_status = false;
    }

    /**
     * @brief Prints information about the device.
     */
    virtual void print_info() const
    {
        std::cout << "Device name: " << name << '\n'
                  << "Device type: " << type << '\n'
                  << "Power status: " << std::boolalpha << power_status
                  << '\n';
    }

    /**
     * @brief Destroys the Device object.
     *
     * The destructor is virtual because Device is used as a base class.
     */
    virtual ~Device()
    {
        std::cout << "Device " << name << " is destroyed." << std::endl;
    }
};

/**
 * @brief Represents a network-capable device that can be shared between rooms.
 */
class SharedDevice : public Device
{
private:
    std::string ip_address;
    bool network_connected;

public:
    /**
     * @brief Constructs a new SharedDevice object.
     *
     * @param device_name Name of the shared device.
     * @param device_type Type of the shared device.
     * @param device_ip_address IP address of the shared device.
     */
    SharedDevice(const std::string &device_name,
                 const std::string &device_type,
                 const std::string &device_ip_address)
        : Device(device_name, device_type),
          ip_address(device_ip_address),
          network_connected(false)
    {
    }

    /**
     * @brief Connects the shared device to the network.
     */
    void connect_to_network()
    {
        network_connected = true;
    }

    /**
     * @brief Disconnects the shared device from the network.
     */
    void disconnect_from_network()
    {
        network_connected = false;
    }

    /**
     * @brief Prints network-specific information about the shared device.
     */
    void print_network_info() const
    {
        std::cout << "IP address: " << ip_address << '\n'
                  << "Network connected: "
                  << std::boolalpha << network_connected
                  << '\n';
    }

    /**
     * @brief Prints general and network-specific device information.
     */
    void print_info() const override
    {
        Device::print_info();
        print_network_info();
    }

    /**
     * @brief Destroys the SharedDevice object.
     */
    ~SharedDevice() override
    {
        std::cout << "SharedDevice " << get_name()
                  << " is destroyed." << std::endl;
    }
};

/**
 * @brief Represents a room containing exclusive and shared devices.
 */
class Room
{
private:
    std::string name;
    std::list<std::unique_ptr<Device>> devices;
    std::list<std::shared_ptr<SharedDevice>> shared_devices;

public:
    /**
     * @brief Constructs a new Room object.
     *
     * @param room_name Name of the room.
     */
    Room(const std::string &room_name)
        : name(room_name)
    {
    }

    /**
     * @brief Adds an exclusive device to the room.
     *
     * Ownership is transferred into the room.
     *
     * @param device Unique pointer to the device.
     */
    void add_device(std::unique_ptr<Device> device)
    {
        devices.push_back(std::move(device));
    }

    /**
     * @brief Adds a shared device to the room.
     *
     * The room receives shared ownership of the device.
     *
     * @param shared_device Shared pointer to the shared device.
     */
    void add_shared_device(std::shared_ptr<SharedDevice> shared_device)
    {
        shared_devices.push_back(shared_device);
    }

    /**
     * @brief Removes an exclusive device from the room by name.
     *
     * @param device_name Name of the device to remove.
     *
     * @return true if the device was found and removed.
     * @return false if no matching device exists.
     */
    bool remove_device_by_name(const std::string &device_name)
    {
        for (auto iterator = devices.begin(); iterator != devices.end(); ++iterator)
        {
            if ((*iterator)->get_name() == device_name)
            {
                devices.erase(iterator);
                return true;
            }
        }

        return false;
    }

    /**
     * @brief Prints all exclusive devices in the room.
     */
    void print_devices() const
    {
        std::cout << "\nExclusive devices in room: " << name << '\n';

        if (devices.empty())
        {
            std::cout << "No exclusive devices in this room." << std::endl;
            return;
        }

        for (const auto &device : devices)
        {
            device->print_info();
            std::cout << '\n';
        }
    }

    /**
     * @brief Prints all shared devices in the room.
     */
    void print_shared_devices() const
    {
        std::cout << "\nShared devices in room: " << name << '\n';

        if (shared_devices.empty())
        {
            std::cout << "No shared devices in this room." << std::endl;
            return;
        }

        for (const auto &shared_device : shared_devices)
        {
            shared_device->print_info();

            std::cout << "Reference counter: "
                      << shared_device.use_count()
                      << "\n\n";
        }
    }

    /**
     * @brief Destroys the Room object.
     */
    ~Room()
    {
        std::cout << "Room " << name << " is destroyed." << std::endl;
    }
};

/**
 * @brief Program entry point.
 *
 * Demonstrates exclusive ownership with std::unique_ptr, shared ownership
 * with std::shared_ptr and inheritance between Device and SharedDevice.
 *
 * @return 0 if the program terminates successfully.
 */
int main()
{
    auto microphone = std::make_unique<Device>(
        "Laptop Microphone",
        "Microphone");

    auto speaker = std::make_unique<Device>(
        "Living Room Speaker",
        "Speaker");

    auto display = std::make_unique<Device>(
        "Conference Display",
        "Display");

    /*
     * Question 1:
     * What happens if you try to copy a std::unique_ptr?
     *
     * A std::unique_ptr cannot be copied. The following code would not compile:
     *
     * std::unique_ptr<Device> copy = microphone;
     *
     * std::unique_ptr represents exclusive ownership. Copying it would create
     * two owners for the same object, which could cause double deletion.
     */

    /*
     * Question 2:
     * Why is std::move(...) required?
     *
     * std::move(...) is required because ownership must be transferred instead
     * of copied. It allows the std::unique_ptr move constructor to transfer
     * ownership to another std::unique_ptr or into a container.
     */

    Room meeting_room("Meeting Room");
    Room living_room("Living Room");

    meeting_room.add_device(std::move(microphone));

    /*
     * Question 3:
     * What happens to the original pointer after moving?
     *
     * After moving, the original std::unique_ptr no longer owns the object.
     * It becomes nullptr.
     */
    if (microphone == nullptr)
    {
        std::cout << "Microphone ownership was moved!" << std::endl;
    }

    living_room.add_device(std::move(speaker));

    if (speaker == nullptr)
    {
        std::cout << "Speaker ownership was moved!" << std::endl;
    }

    meeting_room.add_device(std::move(display));

    if (display == nullptr)
    {
        std::cout << "Display ownership was moved!" << std::endl;
    }

    meeting_room.print_devices();
    living_room.print_devices();

    if (meeting_room.remove_device_by_name("Conference Display"))
    {
        std::cout << "\nConference Display was removed." << std::endl;
    }

    meeting_room.print_devices();

    /*
     * Question 4:
     * When is the destructor automatically called?
     *
     * For std::unique_ptr, the destructor of the managed object is called when
     * the owning std::unique_ptr is destroyed, reset, overwritten, or removed
     * from a container.
     *
     * For std::shared_ptr, the destructor of the managed object is called when
     * the last std::shared_ptr owning the object is destroyed or reset.
     */

    std::cout << "\n--- Shared devices ---\n";

    auto music_server = std::make_shared<SharedDevice>(
        "Central Music Server",
        "Server",
        "192.168.0.10");

    auto network_storage = std::make_shared<SharedDevice>(
        "Network Storage",
        "Storage",
        "192.168.0.20");

    music_server->connect_to_network();
    network_storage->connect_to_network();

    std::cout << "Music server use_count after creation: "
              << music_server.use_count()
              << std::endl;

    std::cout << "Network storage use_count after creation: "
              << network_storage.use_count()
              << std::endl;

    {
        Room kitchen("Kitchen");
        Room office("Office");

        kitchen.add_shared_device(music_server);
        office.add_shared_device(music_server);

        kitchen.add_shared_device(network_storage);
        office.add_shared_device(network_storage);

        std::cout << "\nMusic server use_count after adding to rooms: "
                  << music_server.use_count()
                  << std::endl;

        std::cout << "Network storage use_count after adding to rooms: "
                  << network_storage.use_count()
                  << std::endl;

        kitchen.print_shared_devices();
        office.print_shared_devices();
    }

    std::cout << "\nMusic server use_count after rooms are destroyed: "
              << music_server.use_count()
              << std::endl;

    std::cout << "Network storage use_count after rooms are destroyed: "
              << network_storage.use_count()
              << std::endl;

    /*
     * Reflection Question 1:
     * Why are smart pointers safer than raw pointers?
     *
     * Smart pointers manage memory automatically. They delete owned objects
     * when ownership ends. This reduces memory leaks, forgotten delete calls
     * and unclear ownership.
     */

    /*
     * Reflection Question 2:
     * What problem does std::unique_ptr solve?
     *
     * std::unique_ptr solves exclusive ownership. It makes clear that exactly
     * one pointer owns and deletes the managed object.
     */

    /*
     * Reflection Question 3:
     * Why can std::unique_ptr not be copied?
     *
     * std::unique_ptr cannot be copied because copying would create two owners
     * for one object. That would violate exclusive ownership and could cause
     * double deletion.
     */

    /*
     * Reflection Question 4:
     * What problem does std::shared_ptr solve?
     *
     * std::shared_ptr solves shared ownership. Multiple rooms can own the same
     * shared device, and the object stays alive as long as at least one
     * std::shared_ptr owns it.
     */

    /*
     * Reflection Question 5:
     * What does use_count() represent?
     *
     * use_count() returns the number of std::shared_ptr objects that currently
     * share ownership of the same managed object.
     */

    /*
     * Reflection Question 6:
     * Why can cyclic references become problematic with std::shared_ptr?
     *
     * Cyclic references are problematic because objects can keep each other
     * alive through std::shared_ptr members. Then the reference counters never
     * reach zero, so the objects are never destroyed. This causes a memory leak.
     * Such cycles are usually broken with std::weak_ptr.
     */

    /*
     * Reflection Question 7:
     * Why should the base class destructor be virtual in polymorphic class
     * hierarchies?
     *
     * A virtual base class destructor ensures that the derived destructor is
     * called when an object is deleted through a base class pointer. Without a
     * virtual destructor, only the base part might be destroyed correctly.
     */

    return 0;
}