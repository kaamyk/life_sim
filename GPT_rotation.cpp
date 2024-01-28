#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


// int main() {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Rotate Square Example");

//     // Square properties
//     sf::Vector2f squareSize(100.0f, 100.0f);
//     sf::Vector2f squarePosition(400.0f, 300.0f);
//     sf::RectangleShape square(squareSize);
//     square.setFillColor(sf::Color::White);

//     // Rotation properties
//     const int numAngles = 36;  // Number of angles to rotate
//     const float angleIncrement = 10.0f;  // Angle increment between rotations
//     float currentAngle = 0.0f;

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }
//         }

//         window.clear();

//         // Apply rotation transformation
//         sf::Transform rotationTransform;
//         rotationTransform.rotate(currentAngle, squarePosition.x, squarePosition.y);

//         // Draw rotated square
//         square.setPosition(rotationTransform.transformPoint(squarePosition));
//         square.setRotation(currentAngle);
//         window.draw(square);

//         // Get the coordinates of each vertex after rotation
//         for (unsigned int i = 0; i < 4; ++i) {
//             sf::Vector2f vertex = square.getTransform().transformPoint(square.getPoint(i));
//             std::cout << "Vertex " << i + 1 << ": (" << vertex.x << ", " << vertex.y << ")\n";
//         }

//         window.display();

//         // Increment angle for the next frame
//         currentAngle += angleIncrement;

//         // Pause for a moment to make the rotation visible
//         // sf::sleep(sf::milliseconds(100));
//     }

//     return 0;
// }

bool isRectangleInside(const sf::RectangleShape& innerRect, const sf::RectangleShape& outerRect) {
    sf::Transform innerTransform = innerRect.getTransform();
    sf::Transform outerTransform = outerRect.getTransform();

    // Get the global bounding boxes
    sf::FloatRect innerBounds = innerTransform.transformRect(innerRect.getLocalBounds());
    sf::FloatRect outerBounds = outerTransform.transformRect(outerRect.getLocalBounds());

    return outerBounds.contains(innerBounds.left, innerBounds.top) &&
           outerBounds.contains(innerBounds.left + innerBounds.width, innerBounds.top) &&
           outerBounds.contains(innerBounds.left, innerBounds.top + innerBounds.height) &&
           outerBounds.contains(innerBounds.left + innerBounds.width, innerBounds.top + innerBounds.height);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "SFML Rotated Rectangle Inside Example");

    sf::RectangleShape outerRect(sf::Vector2f(200.0f, 150.0f));
    outerRect.setPosition(50.0f, 50.0f);
    outerRect.setFillColor(sf::Color::Blue);

    sf::RectangleShape innerRect(sf::Vector2f(100.0f, 75.0f));
    innerRect.setPosition(100.0f, 100.0f);
    innerRect.setFillColor(sf::Color::Green);
    innerRect.setRotation(45.0f);  // Rotate the inner rectangle

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(outerRect);
        window.draw(innerRect);

        if (isRectangleInside(innerRect, outerRect)) {
            // Inner rectangle is completely inside the outer rectangle
            innerRect.setFillColor(sf::Color::Green);
        } else {
            // Inner rectangle is not completely inside the outer rectangle
            innerRect.setFillColor(sf::Color::Red);
        }

        window.display();
    }

    return 0;
}