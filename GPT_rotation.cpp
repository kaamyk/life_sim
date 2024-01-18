#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Rotate Square Example");

    // Square properties
    sf::Vector2f squareSize(100.0f, 100.0f);
    sf::Vector2f squarePosition(400.0f, 300.0f);
    sf::RectangleShape square(squareSize);
    square.setFillColor(sf::Color::White);

    // Rotation properties
    const int numAngles = 36;  // Number of angles to rotate
    const float angleIncrement = 10.0f;  // Angle increment between rotations
    float currentAngle = 0.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // Apply rotation transformation
        sf::Transform rotationTransform;
        rotationTransform.rotate(currentAngle, squarePosition.x, squarePosition.y);

        // Draw rotated square
        square.setPosition(rotationTransform.transformPoint(squarePosition));
        square.setRotation(currentAngle);
        window.draw(square);

        // Get the coordinates of each vertex after rotation
        for (unsigned int i = 0; i < 4; ++i) {
            sf::Vector2f vertex = square.getTransform().transformPoint(square.getPoint(i));
            std::cout << "Vertex " << i + 1 << ": (" << vertex.x << ", " << vertex.y << ")\n";
        }

        window.display();

        // Increment angle for the next frame
        currentAngle += angleIncrement;

        // Pause for a moment to make the rotation visible
        // sf::sleep(sf::milliseconds(100));
    }

    return 0;
}