#pragma once
#include <SFML/Graphics.hpp>

#include "Pointers.h"
#include "DrawBatch.h"


#define M_PI 3.14159265359f
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0f)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0f / M_PI)


/*|||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||LineClass|||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
class Line : public sf::VertexArray
{
private:
	// overridings
	void append(const sf::Vertex& vertex) { sf::VertexArray::append(vertex); }
	void clear(){ sf::VertexArray::clear(); }
	void resize(std::size_t vertexCount) { sf::VertexArray::resize(vertexCount); }
	// overridings

public:
	Line(sf::Vertex start, sf::Vertex end);
	
	sf::Vector2f getStartPoint();
	sf::Vector2f getEndPoint();
	sf::Color getStartColor();
	sf::Color getEndColor();

	void setStartPoint(sf::Vector2f p);
	void setEndPoint(sf::Vector2f p);
	void setStartColor(sf::Color c);
	void setEndColor(sf::Color c);
	void setColor(sf::Color c);
};