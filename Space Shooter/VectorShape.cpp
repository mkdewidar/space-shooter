#include "VectorShape.h"
#include "Vector2D.h"

VectorShape::VectorShape(Vector2D center, Vector2D* vertices, int noOfVertices)
{
	this->center = center;

	for (int vertexIndex = 0; vertexIndex < noOfVertices; vertexIndex++)
	{
		this->vertices.push_back(vertices[vertexIndex]);
	}

	this->forwardDirection = this->vertices[0];
}

VectorShape::~VectorShape()
{
}

vector<Vector2D> VectorShape::GetWorldCoords()
{
	// the coords that will be returned
	vector<Vector2D> coords;
	// only need as much memory as the vertices
	coords.reserve(this->vertices.size());

	for (Vector2D point : this->vertices)
	{
		coords.push_back((this->center + point));
	}

	return coords;
}


vector<SDL_Point> VectorShape::GetDrawableCoords()
{
	vector<Vector2D> vectorCoords = this->GetWorldCoords();
	vectorCoords.push_back(vectorCoords.front());

	vector<SDL_Point> coords;

	for (Vector2D vectorPoint : vectorCoords)
	{
		coords.push_back(vectorPoint.GetSDLPoint());
	}

	return coords;
}

vector<Vector2D> VectorShape::GetVectorEdges()
{
	vector<Vector2D> edges;
	
	// edge is the difference between two consecutive vertices
	for (int vertexIndex = 0; vertexIndex < (int)this->vertices.size(); vertexIndex++)
	{
		// if we are on the last vertex the edge is from the
		// last vertex to the first one

		Vector2D newEdge;

		if (vertexIndex == (this->vertices.size() - 1))
		{
			newEdge = Vector2D(this->vertices[0].x - this->vertices[vertexIndex].x,
				this->vertices[0].y - this->vertices[vertexIndex].y);
		}
		else
		{
			newEdge = Vector2D(this->vertices[vertexIndex + 1].x - this->vertices[vertexIndex].x,
				this->vertices[vertexIndex + 1].y - this->vertices[vertexIndex].y);
		}

		edges.push_back(newEdge);
	}

	return edges;
}

void VectorShape::OffsetForward(double scale)
{
	this->center = this->center + (this->forwardDirection.GetUnitVector() * scale);
}

void VectorShape::RotateVertices(double angle)
{
	double angleR = (angle * M_PI) / 180;

	// goes through all of the coordinates and rotates them using the rotation matrix
	for (int vertexCounter = 0; vertexCounter < (int)this->vertices.size(); vertexCounter++)
	{
		Vector2D oldCoords = this->vertices[vertexCounter];

		this->vertices[vertexCounter].x = (oldCoords.x * cos(angleR)) - (oldCoords.y * sin(angleR));
		this->vertices[vertexCounter].y = (oldCoords.x * sin(angleR)) + (oldCoords.y * cos(angleR));
	}

	// TODO: Create a matrix class to stop copy pasting all this
	Vector2D oldCoords = this->forwardDirection;

	this->forwardDirection.x = (oldCoords.x * cos(angleR)) - (oldCoords.y * sin(angleR));
	this->forwardDirection.y = (oldCoords.x * sin(angleR)) + (oldCoords.y * cos(angleR));
}