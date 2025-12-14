#ifndef SOLARSYSTEM_H

#define SOLARSYSTEM_H

#include <string>
#include "Planet.h"
#include <SFML/Graphics.hpp>
#include <vector>

// Represents a 2D solar system simulation.
// Manages a sun at (m_x_sun, m_y_sun) and a dynamic list of planets.
class SolarSystem {
public:
    // Initialize the solar system with sun position (x, y).
    SolarSystem(double x_sun, double y_sun);

    // Adds a planet to the simulation.
    void add_planet(const Planet& planet);

    // Draw the sun at its position.
    void draw_sun(sf::RenderWindow& window) const;

    // Update all planet positions based on elapsed time dt.
    void calculate_planet_pos(float dt);

    // Draw all planets relative to the sun position.
    void draw_planet(sf::RenderWindow& window);

private:
    double m_SunRadius;
    double m_dt;
    double m_x_sun;
    double m_y_sun;

    std::vector<Planet> m_planets;
};

#endif
