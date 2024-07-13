#include "tui.h"

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>

Tui::Tui() = default;

void Tui::start() {
    auto screen = ftxui::ScreenInteractive::Fullscreen();

    ftxui::FlexboxConfig flexboxConfig;
    flexboxConfig.justify_content = ftxui::FlexboxConfig::JustifyContent::SpaceAround;
    flexboxConfig.align_content = ftxui::FlexboxConfig::AlignContent::Center;
    auto window = ftxui::flexbox({
        ftxui::text("Hello, World!") | ftxui::xflex | ftxui::center,
        ftxui::text("Goodbye, World!") | ftxui::xflex | ftxui::center,
    }, flexboxConfig) | ftxui::border;
    auto renderer = ftxui::Renderer([&] { return window; });

    screen.Loop(renderer);
}