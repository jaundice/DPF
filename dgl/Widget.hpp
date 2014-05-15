/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2014 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef DGL_WIDGET_HPP_INCLUDED
#define DGL_WIDGET_HPP_INCLUDED

#include "Geometry.hpp"

START_NAMESPACE_DGL

// -----------------------------------------------------------------------

class App;
class Window;

class Widget
{
public:
    explicit Widget(Window& parent);
    virtual ~Widget();

    bool isVisible() const noexcept;
    void setVisible(bool yesNo);

    void show();
    void hide();

    int getX() const noexcept;
    int getY() const noexcept;
    const Point<int>& getPos() const noexcept;

    void setX(int x) noexcept;
    void setY(int y) noexcept;
    void setPos(int x, int y) noexcept;
    void setPos(const Point<int>& pos) noexcept;

    int getWidth() const noexcept;
    int getHeight() const noexcept;
    const Size<int>& getSize() const noexcept;

    // virtual needed by cairo
    virtual void setWidth(int width) noexcept;
    virtual void setHeight(int height) noexcept;
    virtual void setSize(int width, int height) noexcept;
    virtual void setSize(const Size<int>& size) noexcept;

    const Rectangle<int>& getArea() const noexcept;

    uint getEventTimestamp() const noexcept;
    int  getModifiers() const noexcept;

    App&    getParentApp() const noexcept;
    Window& getParentWindow() const noexcept;

    void repaint() noexcept;

protected:
    virtual void onDisplay() = 0;
    virtual bool onKeyboard(bool press, uint key);
    virtual bool onMouse(int button, bool press, int x, int y);
    virtual bool onMotion(int x, int y);
    virtual bool onScroll(int x, int y, float dx, float dy);
    virtual bool onSpecial(bool press, Key key);
    virtual void onReshape(int width, int height);

private:
    Window& fParent;
    bool    fVisible;
    Rectangle<int> fArea;

    friend class CairoWidget;
    friend class Window;
    friend class StandaloneWindow;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Widget)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DGL

#endif // DGL_WIDGET_HPP_INCLUDED
