#pragma once

#include <SDL.h>
#include <string>
#include <vector>
#include "Vector2D.h"

using std::string;
using std::vector;

/*
Represents any vector shape that can be drawn to the screen
*/
class VectorShape
{
public:

	// the center of the object, is relative to world space
	Vector2D center;

	/*
	Constructor for defining a game object,
	@param center defines the center of the object relative to world space
	@param vertices all of the points which make up the object, relative
			to center param
	@param noOfVertices the number of verticies passed
	*/
	VectorShape(Vector2D center, Vector2D* vertices, int noOfVertices);
	~VectorShape();

	/*
	Gets the vertices relative to the world coordinates
	@return vector of all of the points relative to the
		world coordinates
	*/
	vector<Vector2D> GetWorldCoords();

	/*
	Gets the vertices in a format that draws the object
		using the SDL draw lines function
	@return vector of all of the points in the format required
	*/
	vector<SDL_Point> GetDrawableCoords();

	/*
	Gets all of the edges coords that make up the shape going around clockwise
	@return vector of all of Vector2D's which determine the edges
	*/
	vector<Vector2D> GetVectorEdges();

protected:
	// the vertices which define the objects look,
	// relative to the center coordinate
	vector<Vector2D> vertices;

	// vector representing the direction the object is pointing
	Vector2D forwardDirection;

	/*
	Rotates the vertices that define the game object
	@param angle the angle to rotate by where north is 0 degrees
	angle must be in eular angles
	*/
	void RotateVertices(double angle);
};