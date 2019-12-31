#pragma once

#include "Song.h"
#include "../core/Component.h"
#include <memory>

namespace engine::audio {

class AudioSource : public core::Component {
public:
    AudioSource(std::unique_ptr<Song> song) : song_{std::move(song)} {}
    void play() const;
    void play(const int volume) const;
    void setVolume(const int volume) const;
private:
    std::unique_ptr<Song> song_;
};

}