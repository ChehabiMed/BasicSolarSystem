#include <iostream>
#include <string>
#include <cmath>
#include "Planet.h"
#include <SFML/Graphics.hpp>



// Initializes a planet with scaled physical parameters suitable for real-time rendering.
// Astronomical values are intentionally rescaled to keep the simulation visible and stable.
Planet::Planet(double Radius, double OrbitSpeed, double DistanceFromSun, const std::string& Color)
    : m_CurrentAngle(0),
    m_DistanceFromSun(DistanceFromSun * 1.1),   // distance scaling factor
    m_Radius(Radius * 0.0010),                  // radius scaling factor
    m_OrbitSpeed(OrbitSpeed * 0.1),             // orbital period scaling factor
    m_Color(Color),
    m_position(DistanceFromSun, 0)

{

}



// Updates the planet position assuming a circular orbit in the XY plane.
// Motion is time-based to ensure frame-rate independent behavior.
void Planet::ComputePosition(double dt)
{
  
  
    // Convert orbital period to angular velocity (radians per second)
    m_CurrentAngle += ((2 * M_PI) / m_OrbitSpeed) * dt;
      
     
    m_position.x = m_DistanceFromSun * cos(m_CurrentAngle);
    m_position.y = m_DistanceFromSun * sin(m_CurrentAngle);

    
     
    
}
  
  
    sf::Vector2f Planet::get_position() const { return m_position; }

    double Planet::getDistanceFromSun() const { return m_DistanceFromSun; }
    double Planet::getRadius() const { return m_Radius; }
    double Planet::getOrbitSpeed() const { return m_OrbitSpeed; }
    std::string Planet::getColor() const { return m_Color; }
