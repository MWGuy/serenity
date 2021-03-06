/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <LibGUI/GApplication.h>
#include <LibGUI/GBoxLayout.h>
#include <LibGUI/GButton.h>
#include <LibGUI/GLabel.h>
#include <LibGUI/GWidget.h>
#include <LibGUI/GWindow.h>

int main(int argc, char** argv)
{
    GApplication app(argc, argv);

    auto window = GWindow::construct();
    window->set_rect(100, 100, 240, 160);
    window->set_title("Hello World!");

    auto main_widget = GWidget::construct();
    window->set_main_widget(main_widget);
    main_widget->set_fill_with_background_color(true);
    main_widget->set_background_color(Color::White);
    main_widget->set_layout(make<GBoxLayout>(Orientation::Vertical));
    main_widget->layout()->set_margins({ 4, 4, 4, 4 });

    auto label = GLabel::construct(main_widget);
    label->set_text("Hello\nWorld!");

    auto button = GButton::construct(main_widget);
    button->set_text("Good-bye");
    button->set_size_policy(SizePolicy::Fill, SizePolicy::Fixed);
    button->set_preferred_size(0, 20);
    button->on_click = [&](GButton&) {
        app.quit();
    };

    window->show();

    return app.exec();
}
