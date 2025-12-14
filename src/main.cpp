#include <iostream>
#include <SFML/Graphics.hpp>
#include "Planet.h"
#include "SolarSystem.h"

// Window dimensions
int x_window_size(1800);
int y_window_size(1100);

// Initialize planets (radius in km, orbit period in days, distance in 10^6 km)
Planet p_mercury(2440, 88, 57.91, "red");
Planet p_venus(6052, 225, 108.2, "green");
Planet p_earth(6371, 365.26, 149.6, "blue");
Planet p_mars(3390, 687, 227.9, "cyan");
Planet p_jupiter(69911, 4333, 778.5, "white");

// Create solar system centered in the window
SolarSystem sun(x_window_size, y_window_size);

int main() {
    sf::RenderWindow window(sf::VideoMode(x_window_size,y_window_size), "Solar System Simulation");
    sf::Clock clock;

    // Add planets to solar system
    sun.add_planet(p_mercury);
    sun.add_planet(p_venus);
    sun.add_planet(p_earth);
    sun.add_planet(p_mars);
    sun.add_planet(p_jupiter);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Compute elapsed time since last frame
        float dt = clock.restart().asSeconds();

        // Update planet positions
        sun.calculate_planet_pos(dt);

        // Draw everything
        window.clear();
        sun.draw_sun(window);
        sun.draw_planet(window);
        window.display();
    }
}

