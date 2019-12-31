#include "AudioSource.h"
#if defined(_WIN32)
    #include <SDL.h>
    #include <SDL_mixer.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_mixer.h>
#endif
#include <cassert>

namespace engine::audio {

void AudioSource::play() const
{
    static constexpr int REPEAT_MUSIC_SETTING = -1;
    Mix_PlayMusic(song_->get(), REPEAT_MUSIC_SETTING);
}

void AudioSource::play(const int volume) const
{
    setVolume(volume);
    play();
}

void AudioSource::setVolume(const int volume) const
{
    assert(volume >= 0 && volume <= MIX_MAX_VOLUME);
    Mix_VolumeMusic(volume);
}

}