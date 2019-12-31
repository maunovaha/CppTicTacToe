#include "MusicPlayer.h"
#include "../../engine/audio/AudioSource.h"
#include "../../engine/audio/Song.h"
#include <memory>

namespace game::shared {

using namespace engine;

MusicPlayer::MusicPlayer()
{
     auto backgroundMusic = std::make_unique<audio::Song>("assets/sounds/Pamgaea.mp3");
     auto backgroundMusicSource = std::make_unique<audio::AudioSource>(std::move(backgroundMusic));

     addComponent(std::move(backgroundMusicSource));
}

}
