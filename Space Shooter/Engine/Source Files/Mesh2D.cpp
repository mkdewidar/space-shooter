#include "../Header Files/Mesh2D.h"
#include "../Header Files/Vector2D.h"


Mesh2D::Mesh2D(Vector2D* vertices, int noOfVertices)
{
	for (size_t vertexIndex = 0; vertexIndex < (size_t)noOfVertices; vertexIndex++)
	{
		this->vertices.push_back(vertices[vertexIndex]);
	}

	this->forwardDirection = this->vertices[0];
}

Mesh2D::~Mesh2D()
{
}

vector<SDL_Point> Mesh2D::GetDrawableCoords(Vector2D position)
{
	vector<Vector2D> worldCoords;

	// only need as much memory as the vertices
	worldCoords.reserve(this->vertices.size());

	for (Vector2D point : this->vertices)
	{
		worldCoords.push_back((position + point));
	}

	worldCoords.push_back(worldCoords.front());

	vector<SDL_Point> coords;

	for (Vector2D vectorPoint : worldCoords)
	{
		coords.push_back(vectorPoint.GetSDLPoint());
	}

	return coords;
}

vector<Vector2D> Mesh2D::GetVectorEdges()
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

void Mesh2D::RotateVertices(double angle)
{
	double angleR = (angle * M_PI) / 180;

	// goes through all of the coordinates and rotates them using the rotation matrix
	for (int vertexCounter = 0; vertexCounter < (int)this->vertices.size(); vertexCounter++)
	{
		Vector2D oldCoords = this->vertices[vertexCounter];

		this->vertices[vertexCounter].x = (oldCoords.x * cos(angleR)) - (oldCoords.y * sin(angleR));
		this->vertices[vertexCounter].y = (oldCoords.x * sin(angleR)) + (oldCoords.y * cos(angleR));
	}

	Vector2D oldCoords = this->forwardDirection;

	this->forwardDirection.x = (oldCoords.x * cos(angleR)) - (oldCoords.y * sin(angleR));
	this->forwardDirection.y = (oldCoords.x * sin(angleR)) + (oldCoords.y * cos(angleR));
}