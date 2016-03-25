#include "../Header Files/Vector2D.h"



Vector2D::Vector2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D()
{
}

Vector2D::~Vector2D()
{
}

double Vector2D::GetMagnitude()
{
	double magnitude;

	magnitude = sqrt( (this->x * this->x) + (this->y * this->y) );

	return magnitude;
}

double Vector2D::GetDotProduct(Vector2D otherVector)
{
	return (this->x * otherVector.x) + (this->y * otherVector.y);
}

Vector2D Vector2D::GetNormal()
{
	return Vector2D(-this->y, this->x);
}

Vector2D Vector2D::GetUnitVector()
{
	Vector2D unitVector;
	double magnitude = GetMagnitude();

	unitVector = { (this->x / magnitude), (this->y / magnitude) };

	return unitVector;
}

Vector2D Vector2D::operator+(Vector2D otherVector)
{
	return Vector2D( (this->x + otherVector.x), (this->y + otherVector.y));
}

Vector2D Vector2D::operator-(Vector2D otherVector)
{
	return Vector2D((this->x - otherVector.x), (this->y - otherVector.y));
}

Vector2D Vector2D::operator*(double scalar)
{
	return Vector2D((this->x * scalar), (this->y * scalar));
}

Vector2D Vector2D::GetProjection(Vector2D vToProject)
{
	// projection is kinda like shadow of one vector onto another
	// in this case the shadow of vToProject onto this vector

	Vector2D projection;

	Vector2D thisUnitVector = this->GetUnitVector();
	projection = thisUnitVector * thisUnitVector.GetDotProduct(vToProject);
	
	return projection;
}

SDL_Point Vector2D::GetSDLPoint()
{
	SDL_Point point;
	point.x = (int)this->x;
	point.y = (int)this->y;
	return point;
}
