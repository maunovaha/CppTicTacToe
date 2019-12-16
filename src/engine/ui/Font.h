#pragma once

#include "Color.h"
#include "../gfx/Surface.h"
#if defined(_WIN32)
    #include <SDL.h>
    #include <SDL_ttf.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
#endif
#include <string>
#include <memory>

namespace engine::ui {

class Font {
public:
    Font(const std::string& filePath, const int size);
    gfx::Surface renderBlended(const std::string& text, const Color& color) const;
    TTF_Font* get() const;
private:
    struct DestroyFont {
        void operator()(TTF_Font* font) const
        {
            TTF_CloseFont(font);
        }
    };

    using UniqueFont = std::unique_ptr<TTF_Font, DestroyFont>;

    UniqueFont font_;
};

}
