
#ifndef COMPLEXPLANE_H
#define COMPLEXPLANE_H

#include <SFML/Graphics.hpp>
#include <complex>

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0f;
const float BASE_HEIGHT = 4.0f;
const float BASE_ZOOM = 0.5f;

class ComplexPlane : public sf::Drawable {
public:
    ComplexPlane(int pixelWidth, int pixelHeight);
    void updateRender();
    void zoomIn();
    void zoomOut();
    void setCenter(sf::Vector2i mousePixel);
    void setMouseLocation(sf::Vector2i mousePixel);
    void loadText(sf::Text& text);
    
private:
    enum class State { CALCULATING, DISPLAYING };
    sf::VertexArray m_vArray;
    sf::Vector2f m_plane_center;
    sf::Vector2f m_plane_size;
    sf::Vector2f m_mouseLocation;
    int m_pixel_width;
    int m_pixel_height;
    float m_aspectRatio;
    int m_zoomCount;
    State m_State;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    size_t countIterations(sf::Vector2f coord);
    void iterationsToRGB(size_t count, sf::Uint8& r, sf::Uint8& g, sf::Uint8& b);
    sf::Vector2f mapPixelToCoords(sf::Vector2i pixel);
};

#endif
