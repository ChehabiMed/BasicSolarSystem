#ifndef PLANET_H

#define PLANET_H

#include <string>
#include <utility>
#include <SFML/Graphics.hpp>


class Planet {
public:
    
    Planet(double Radius, double OrbitSpeed, double DistanceFromSun, const std::string& Color); // Initialize planet with size, orbit, distance, color
    void ComputePosition(double dt);          // Update position based on elapsed time
    sf::Vector2f get_position() const;       // Get current position
    double getDistanceFromSun() const;       // Get orbit radius
    double getRadius() const;                // Get planet radius
    double getOrbitSpeed() const;            // Get orbit period
    std::string getColor() const;            // Get planet color

    
private:
    double m_CurrentAngle;
    double m_DistanceFromSun;
    double m_Radius;
    double m_OrbitSpeed;
    std::string m_Color;
    
    sf::Vector2f m_position;

};

#endif 
