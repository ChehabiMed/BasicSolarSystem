#include <iostream>
#include <string>
#include <cmath>
#include "SolarSystem.h"
#include "Planet.h"
#include <SFML/Graphics.hpp>
#include <vector>


// Constructor: initialize sun position and radius
SolarSystem::SolarSystem(double x_sun, double y_sun)
    : m_SunRadius(45), m_x_sun(x_sun/2), m_y_sun(y_sun/2)
{}

// Draw the sun at the center of the window
void SolarSystem::draw_sun(sf::RenderWindow& window) const {
    sf::CircleShape circle(m_SunRadius);
    circle.setOrigin(m_SunRadius, m_SunRadius);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(m_x_sun, m_y_sun);
    window.draw(circle);
}

// Add a planet to the system
void SolarSystem::add_planet(const Planet& planet){
    m_planets.push_back(planet);
}

// Update all planet positions based on elapsed time dt
void SolarSystem::calculate_planet_pos(float dt){
    for(int i=0; i < m_planets.size(); i++){
        m_planets[i].ComputePosition(dt);
    }
}

// Draw planets and their orbit paths
void SolarSystem::draw_planet(sf::RenderWindow& window){
    for(int i=0; i < m_planets.size(); i++){
        sf::Vector2f pos = m_planets[i].get_position();
        double x = m_x_sun + pos.x;
        double y = m_y_sun + pos.y;

        // Map color string to SFML color
        sf::Color color;
        if (m_planets[i].getColor() == "red") color = sf::Color::Red;
        else if (m_planets[i].getColor() == "blue") color = sf::Color::Blue;
        else if (m_planets[i].getColor() == "green") color = sf::Color::Green;
        else if (m_planets[i].getColor() == "cyan") color = sf::Color::Cyan;
        else color = sf::Color::White;

        // Draw planet
        sf::CircleShape circle(m_planets[i].getRadius());
        circle.setOrigin(m_planets[i].getRadius(), m_planets[i].getRadius());
        circle.setFillColor(color);
        circle.setPosition(x, y);
        window.draw(circle);

        // Draw orbit path
        sf::CircleShape orbit(m_planets[i].getDistanceFromSun());
        orbit.setOrigin(m_planets[i].getDistanceFromSun(), m_planets[i].getDistanceFromSun());
        orbit.setPosition(m_x_sun, m_y_sun);
        orbit.setFillColor(sf::Color::Transparent);
        orbit.setOutlineThickness(1.f);
        orbit.setOutlineColor(sf::Color(200, 200, 200));
        window.draw(orbit);
    }
}


