#ifndef DISPLAY__GRAPHICS_H
#define DISPLAY__GRAPHICS_H

#include <SDL.h>
#include <string>
#include <vector>

#include "deprecated.h"
#include "palette.h"
#include "legacy_surface.h"

namespace display
{

class LegacySurface;

class Graphics
{
public:
    Graphics();
    ~Graphics();

    static const int WIDTH = 320;
    static const int HEIGHT = 200;
    static const int VIDEO_WIDTH = 160;
    static const int VIDEO_HEIGHT = 100;
    static const int NEWS_WIDTH = 312;
    static const int NEWS_HEIGHT = 106;

    int SCALE = 4; // SCALE is now a variable to allow Scale Filters

    void create(const std::string &title, bool fullscreen);
    void destroy();

    SDL_Surface *scaledScreenSurface() const
    {
        return _scaledScreen;
    }

    SDL_Surface *displaySurface() const
    {
        return _display;
    }

    SDL_Overlay *videoOverlay() const
    {
        return _video;
    }

    SDL_Overlay *newsOverlay() const
    {
        return _news;
    }

    Surface *screen() const
    {
        return _screen;
    }

    DEPRECATED(LegacySurface *legacyScreen());

    SDL_Rect &videoRect()
    {
        return _videoRect;
    }

    SDL_Rect &newsRect()
    {
        return _newsRect;
    }

    char foregroundColor() const
    {
        return _foregroundColor;
    }

    char backgroundColor() const
    {
        return _backgroundColor;
    }

    void setForegroundColor(char color);
    void setBackgroundColor(char color);
    void updateScale(int scale);

private:
    LegacySurface *_screen;
    SDL_Surface *_scaledScreen;
    SDL_Surface *_display;
    SDL_Overlay *_video;
    SDL_Overlay *_news;
    SDL_Rect _videoRect;
    SDL_Rect _newsRect;
    char _foregroundColor;
    char _backgroundColor;
};

extern Graphics graphics;

};

#endif // DISPLAY__GRAPHICS_H
