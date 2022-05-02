#pragma once
#include <random>
#include <array>

//using namespace std;

class Random
{
    public:
    Random() 
    {
        //
    }
    int randint(int min, int max) 
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
    std::string randstr(int length, std::string addchars = "") 
    {
        std::string rstr = "";
        std::string strarr = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM" + addchars;
        for (int i=0;i<length;i++)
        {
            rstr += strarr[(*this).randint(0, strarr.length())];
        }
        return rstr;
    }
    std::string choice(
        std::vector<std::string> array
    )
    {
        return array[(*this).randint(0, array.size() - 1)];
    }
    /*std::vector<std::string> choices(
        std::vector<std::string> array,
        int length
    )
    {
        std::vector<std::string> rarray = {};
        for (int i=0;i<length;i++)
        {
            std::vector<std::string> value = {(*this).choice(array)};
            rarray.push_back(value);
        }
        rarray.reserve(rarray.size());
        return rarray;
    }*/
};
