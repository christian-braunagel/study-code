#include <iostream>
#include <string>

class AudioFile
{
public:
    // play() is now virtual -> dynamic binding
    virtual void play() const
    {
        std::cout << "Playing generic audio file\n";
    }

    virtual void print_info() const
    {
        std::cout << "Generic audio file\n";
    }

    // destructor is now virtual to enable calling
    // when derived classes are being destroyed
    virtual ~AudioFile()
    {
        std::cout << "AudioFile destroyed\n";
    }
};

class MP3File : public AudioFile
{
private:
    std::string artist;

public:
    MP3File(const std::string &artist_name)
        : artist(artist_name)
    {
    }

    // corrected signature and override
    void play() const override
    {
        std::cout << "Playing MP3 by " << artist << "\n";
    }

    // corrected signature and override
    void print_info() const override
    {
        std::cout << "MP3 file by " << artist << "\n";
    }

    ~MP3File() override
    {
        std::cout << "MP3File destroyed\n";
    }
};

class WAVFile : public AudioFile
{
public:
    // corrected missing override
    void play() const override
    {
        std::cout << "Playing WAV file\n";
    }

    // corrected missing override
    void print_info() const override
    {
        std::cout << "Uncompressed WAV file\n";
    }

    ~WAVFile() override
    {
        std::cout << "WAVFile destroyed\n";
    }
};

int main()
{
    AudioFile *playlist[2];

    playlist[0] = new MP3File("Daft Punk");
    playlist[1] = new WAVFile();

    for (int index = 0; index < 2; index++)
    {
        playlist[index]->print_info();
        playlist[index]->play();
    }

    for (int index = 0; index < 2; index++)
    {
        delete playlist[index];
        // optionally here because program ends here
        playlist[index] = nullptr;
    }

    return 0;
}