#ifndef ENGINE_DIRECTOR_H
#define ENGINE_DIRECTOR_H

#include "Scene.h"
#include <memory>

namespace engine {

class Director {
public:
    static void play(std::unique_ptr<Scene> scene);
    static bool is_playing();
    static const Director* const get();
private:
    Director() = default;

    static inline std::unique_ptr<Scene> current_scene_;
};

}

#endif