
#ifndef _RANDOM_H_
#define _RANDOM_H_

#include <random>
#include <stdexcept>
#include <string>
#include <vector>

class Random 
{
    protected:
    double number;
    public:
    Random() 
    {
        std::random_device rd;
        std::mt19937_64 gen(rd());
        std::uniform_real_distribution<> dist(0, 1);
        number = dist(gen);
    }
    /// randomize
    static Random* randomize()
    {
        return new Random();
    }
    /// returns 0-1 random double
    inline double random();
    /// returns 0-1 random int
    inline int random_int();
    /// returns random bool
    inline bool random_bool(
        unsigned int chance = 50
    );
    /// returns min-max random double
    inline double random_range(
        double min,
        double max
    );
    /// returns min-max random int
    inline int random_range_int(
        int min,
        int max
    );
    /// returns random char in argument `chars`
    inline char random_char(
        const char* chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    );
    /// returns random std::string in argument `string` with length `length`
    /*inline std::string random_string(
        int length = 1,
        std::string string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    );*/
    /// returns random value from `arr`
    inline std::string choice(
        std::vector<std::string> arr
    );
    /// returns random `array` from `arr` with length `length`
    inline std::vector<std::string> choices(
        int length,
        std::vector<std::string> arr
    );
};

double Random::random()
{
    return this->number;
}

int Random::random_int()
{
    return (int)(this->number * 2);
}

bool Random::random_bool(unsigned int chance)
{
    if (chance != 50)
    {
        if (this->random_range(0, 100) >= chance) {
            return true;
        } else {
            return false;
        }
    } else {
        return (bool)(this->random_int());
    }
}

double Random::random_range(double min, double max)
{
    if (min > max)
    {
        throw std::invalid_argument("argument \"min\" more than argument \"min\"");
    }
    return -(min - (this->random() * (max - min)));
}

int Random::random_range_int(int min, int max)
{
    if (min > max)
    {
        throw std::invalid_argument("argument \"min\" more than argument \"min\"");
    }
    return -(int)(min - (this->random() * (max - min)));
}

char Random::random_char(const char* chars)
{
    return chars[this->random_range_int(0, strlen(chars) - 1)];
}

std::string Random::choice(std::vector<std::string> arr)
{
    return arr[this->random_range_int(0, arr.size())];
}

std::vector<std::string> Random::choices(int length, std::vector<std::string> arr)
{
    std::vector<std::string> return_vector = {};
    for (int i=0; i < length; i++)
    {
        return_vector.push_back(this->randomize()->choice(arr));
    }
    return return_vector;
}

#endif
