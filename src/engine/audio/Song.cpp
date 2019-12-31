#include "Song.h"
#include <stdexcept>

namespace engine::audio {

Song::Song(const std::string& path) : song_{Mix_LoadMUS(path.c_str())}
{
    if (!song_) {
        throw std::runtime_error("Could not load song, " + std::string{Mix_GetError()});
    }
}

Mix_Music* Song::get() const
{
    return song_.get();
}

}