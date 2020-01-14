#include "AppDelegate.h"
#include "mainmenu/MainMenuScene.h"

namespace game {

AppDelegate::AppDelegate(const std::string& title, 
                         const engine::ui::Color& backgroundColor, 
                         const int width, 
                         const int height)
    : engine::core::Application{title, backgroundColor, width, height}
{
    run(std::make_unique<mainmenu::MainMenuScene>());
}

}