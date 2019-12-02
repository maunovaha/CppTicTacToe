#include "AppDelegate.h"

namespace game {

AppDelegate::AppDelegate(const std::string& title, const int width, const int height)
    : engine::Application{title, width, height}
{
}

}