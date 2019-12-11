#pragma once

#include "Surface.h"
#if defined(_WIN32)
    #include <SDL.h>
    #include <SDL_ttf.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
#endif
#include <string>
#include <memory>

namespace sdl2wrap {

class Font {
public:
    Font(const std::string& filePath, const int size);
    Surface renderBlended(const std::string& text, const SDL_Color& color) const;
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