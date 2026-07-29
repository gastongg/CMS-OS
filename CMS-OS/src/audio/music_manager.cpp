#include "music_manager.h"

#include <filesystem>
#include <iostream>


namespace fs = std::filesystem;



MusicManager::MusicManager()
{

}




bool MusicManager::scanFolder(
    const std::string& path
)
{

    tracks.clear();


    try
    {

        for(const auto& file : fs::directory_iterator(path))
        {

            if(!file.is_regular_file())
                continue;


            std::string ext =
            file.path().extension().string();



            if(
                ext == ".mp3" ||
                ext == ".wav" ||
                ext == ".flac" ||
                ext == ".ogg"
            )
            {

                Track track;


                track.filename =
                file.path().string();


                track.title =
                file.path().stem().string();


                track.artist = "Unknown";


                tracks.push_back(track);

            }

        }

    }
    catch(...)
    {

        std::cout
        << "No se pudo abrir carpeta de musica"
        << std::endl;


        return false;

    }



    std::cout
    << "Tracks encontrados: "
    << tracks.size()
    << std::endl;



    return true;

}





int MusicManager::getTrackCount() const
{

    return tracks.size();

}





const Track& MusicManager::getTrack(
    int index
) const
{

    return tracks.at(index);

}