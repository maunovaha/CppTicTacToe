#include "AppDelegate.h"
#include "main_menu/MainMenuScene.h"

namespace game {

AppDelegate::AppDelegate(const std::string& title, const int width, const int height)
    : engine::Application{title, width, height}
{
    start(std::make_unique<main_menu::MainMenuScene>());
}

}