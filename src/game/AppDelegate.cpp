#include "AppDelegate.h"
#include "mainmenu/MainMenuScene.h"

namespace game {

AppDelegate::AppDelegate(const std::string& title, const int width, const int height) 
    : engine::core::Application{title, width, height}
{
    run(std::make_unique<mainmenu::MainMenuScene>());
}

}