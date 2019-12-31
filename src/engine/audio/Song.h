#pragma once

#if defined(_WIN32)
    #include <SDL.h>
    #include <SDL_mixer.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_mixer.h>
#endif
#include <string>
#include <memory>

namespace engine::audio {

class Song {
public:
    Song(const std::string& path);
    Mix_Music* get() const;
private:
    struct DestroySong {
        void operator()(Mix_Music* music) const
        {
            Mix_FreeMusic(music);
        }
    };

    using UniqueSong = std::unique_ptr<Mix_Music, DestroySong>;
    UniqueSong song_;
};

}