#include "tui.h"

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>

Tui::Tui() = default;

void Tui::start() {
    auto screen = ftxui::ScreenInteractive::Fullscreen();

    auto left_renderer = ftxui::Renderer([&] {
        return ftxui::paragraph("Hello, World!") | ftxui::hcenter | ftxui::vcenter;
    });

    auto right_renderer = ftxui::Renderer([&] {
        return ftxui::paragraph("Goodbye, World!") | ftxui::hcenter | ftxui::vcenter;
    });

    int pos = ftxui::Terminal::Size().dimx / 2;
    auto content_renderer = ftxui::ResizableSplitLeft(left_renderer, right_renderer, &pos) | ftxui::border;

    screen.Loop(content_renderer);
}