#include "AudioSource.h"
#if defined(_WIN32)
    #include <SDL.h>
    #include <SDL_mixer.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_mixer.h>
#endif
#include <cassert>

////
#include <iostream>

namespace engine::audio {

void AudioSource::play() const
{
    if (isPlaying()) {
        return;
    }

    static constexpr int REPEAT_MUSIC = -1;
    Mix_PlayMusic(song_->get(), REPEAT_MUSIC);
}

void AudioSource::play(const int volume) const
{
    play();
    setVolume(volume);
}

bool AudioSource::isPlaying() const
{
    static constexpr int MUSIC_PLAYING = 1;
    return Mix_PlayingMusic() == MUSIC_PLAYING;
}

void AudioSource::setVolume(const int volume) const
{
    assert(volume >= 0 && volume <= MIX_MAX_VOLUME);
    Mix_VolumeMusic(volume);
}

}