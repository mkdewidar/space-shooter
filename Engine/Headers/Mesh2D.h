#pragma once

#include "SDL.h"
#include <string>
#include <vector>
#include "Vector2D.h"
#include "GameComponent.h"

using std::string;
using std::vector;

/*
Represents any vector shape that can be drawn to the screen
*/
class Mesh2D
	: public GameComponent
{
public:

	/*
	Constructor for defining a game object,
	@param vertices all of the points which make up the object, relative
			to 0,0 local space
	@param noOfVertices the number of verticies passed
	*/
	Mesh2D(Vector2D* vertices, int noOfVertices);
	~Mesh2D();

	/*
	Gets the vertices in a format that draws the object
		using the SDL draw lines function
	@param position the position of the mesh in the space to be
		drawn in.
	@return vector of all of the points in the format required
	*/
	vector<SDL_Point> GetDrawableCoords(Vector2D position);

	/*
	Convert the coordinates to space provided
	@param position the position of the mesh in the space the 
		coords are to be in.
	@return vector of all of the points in the space
	*/
	vector<Vector2D> GetCoordsInSpace(Vector2D position);

	/*
	Gets all of the edges coords that make up the shape going around clockwise
	@return vector of all of Vector2D's which determine the edges
	*/
	vector<Vector2D> GetVectorEdges();

	/*
	Rotates the vertices that define the game object
	@param angle the angle to rotate by where north is 0 degrees
		angle must be in eular angles
	*/
	void RotateVertices(double angle);

	// vector representing the direction the object is pointing
	Vector2D forwardDirection;

protected:
	// the vertices which define the objects look,
	// relative to the origin coordinate
	vector<Vector2D> vertices;
};