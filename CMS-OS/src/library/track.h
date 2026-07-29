#pragma once

#include <string>


class Track
{

public:

    Track();


    std::string filename;

    std::string title;

    std::string artist;

    std::string album;

    std::string genre;

    std::string key;


    float bpm;

    int duration;

};