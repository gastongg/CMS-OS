#pragma once

#include <vector>
#include <string>

#include "../library/track.h"


class MusicManager
{

public:

    MusicManager();


    bool scanFolder(
        const std::string& path
    );


    int getTrackCount() const;


    const Track& getTrack(
        int index
    ) const;



private:

    std::vector<Track> tracks;

};