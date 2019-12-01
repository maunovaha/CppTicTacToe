#include "InitImage.h"
#include <stdexcept>
#include <string>

namespace SDL2wrap {

InitImage::InitImage(const int flags)
{
    if (!(IMG_Init(flags) & flags)) {
        throw std::runtime_error("Could not init SDL_image, " + std::string{IMG_GetError()});
    }
}

InitImage::~InitImage()
{
    IMG_Quit();
}

}
