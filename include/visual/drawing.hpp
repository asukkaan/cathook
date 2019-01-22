/*
 * drawing.h
 *
 *  Created on: Oct 5, 2016
 *      Author: nullifiedcat
 */

#pragma once

#include <glez/font.hpp>
#include "common.hpp"

class CachedEntity;
class Vector;
class IClientEntity;
class CatEnum;
class VMatrix;

namespace fonts
{

extern std::unique_ptr<glez::font> esp;
extern std::unique_ptr<glez::font> menu;
extern unsigned long surface_font;

void Update();

extern const std::vector<std::string> fonts;
extern CatEnum family_enum;
} // namespace fonts

constexpr rgba_t GUIColor()
{
    return colors::white;
}

void InitStrings();
void ResetStrings();
void AddCenterString(const std::string &string, const rgba_t &color = colors::white);
void AddSideString(const std::string &string, const rgba_t &color = colors::white);
void DrawStrings();

namespace draw
{

extern std::mutex draw_mutex;
extern VMatrix wts;

extern int width;
extern int height;
extern float fov;

void Initialize();

#if ENABLE_ENGINE_DRAWING
class Texture
{
public:
    explicit Texture(std::string path) : path{ path }
    {
    }
    bool load();
    unsigned int get();
    ~Texture();
    unsigned int getWidth()
    {
        return m_width;
    }
    unsigned int getHeight()
    {
        return m_height;
    }

private:
    std::string path;
    unsigned int texture_id = 0;
    unsigned char *data     = nullptr;
    bool init               = false;
    int m_width, m_height;
};
#else
typedef glez::texture Texture;
#endif

void Line(float x1, float y1, float x2, float y2, rgba_t color, float thickness);
void String(int x, int y, rgba_t rgba, const char *text);
void Rectangle(float x, float y, float w, float h, rgba_t color);
void RectangleOutlined(float x, float y, float w, float h, rgba_t color, float thickness);
void RectangleTextured(float x, float y, float w, float h, rgba_t color, Texture &texture, float tx, float ty, float tw, float th, float angle);

void UpdateWTS();
bool WorldToScreen(const Vector &origin, Vector &screen);
bool EntityCenterToScreen(CachedEntity *entity, Vector &out);

void InitGL();
void BeginGL();
void EndGL();

} // namespace draw
