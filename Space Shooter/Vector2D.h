#pragma once

#include <SDL.h>

/*
Represents a set of 2D coordinates in a 2D world
*/
class Vector2D
{
public:
	double x;
	double y;

	Vector2D(double x, double y);
	Vector2D();
	~Vector2D();

	/*
	Get the magnitude of the vector
	@return the magnitude of the vector
	*/
	double GetMagnitude();

	/*
	Get the dot product of the vector with the one provided
	@return the dot product
	*/
	double GetDotProduct(Vector2D otherVector);

	/*
	Get the vector representing the left normal
	@return a vector representing the left normal
		to the current vector
	*/
	Vector2D GetNormal();

	/*
	Get the unit vector of the (magnitude of 1)
	@return the unit vector of the current vector
	*/
	Vector2D GetUnitVector();

	/*
	Projects the vector provided on the current vector
	@param vToProject the vector that is to be projected
		on the current vector
	@return vector representing the projection onto 
		the current vector
	*/
	Vector2D GetProjection(Vector2D vToProject);

	/*
	Converts the current Vector2D to an SDL_Point
	@return SDL_Point of the current vector
	*/
	SDL_Point GetSDLPoint();

	/*
	Operator overload for the +, allows adding of two vectors
	@param otherVector the other vector that is to be added
		to the current vector
	@return vector representing the sum of the 2 vectors
	*/
	Vector2D operator + (Vector2D otherVector);

	/*
	Operator overload for the -, provides the difference of two vectors
	@param otherVector the other vector that is to subtracted
		from the current vector
	@return vector represeting the difference between the vectors
	*/
	Vector2D operator - (Vector2D otherVector);

	/*
	Operator overload for the *, allows for scalar multiplication of a vector
	@param the scalar to multiply the vector by
	@return vector represeting the new scaled vector
	*/
	Vector2D operator * (double scalar);

};

