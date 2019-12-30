#pragma once

#include "../shared/Player.h"
#include "../../engine/scene/Scene.h"
#include "../../engine/ui/Color.h"
#include <string>
#include <memory>

namespace game::gameover {

class GameOverScene : public engine::scene::Scene {
public:
    GameOverScene(std::unique_ptr<shared::Player> winner = std::unique_ptr<shared::Player>{nullptr})
        : winner_{std::move(winner)} {}
    void onCreate() override;
private:
    void createGameOverText(const std::string& text,
                            const std::string& font,
                            const int size,
                            const int yPosition,
                            const engine::ui::Color& color = engine::ui::Color::black());
    void createPlayAgainButton(const std::string& text,
                               const std::string& font, 
                               const int size,
                               const int paddingLeft,
                               const int paddingBottom,
                               const engine::ui::Color& color = engine::ui::Color::black());
    void createQuitButton(const std::string& text,
                          const std::string& font,
                          const int size,
                          const int paddingRight,
                          const int paddingBottom,
                          const engine::ui::Color& color = engine::ui::Color::black());
    std::string getGameResult() const;

    std::unique_ptr<shared::Player> winner_;
};

}
