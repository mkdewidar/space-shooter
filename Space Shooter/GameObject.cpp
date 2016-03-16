#include "GameObject.h"
#include <Windows.h>



GameObject::GameObject(Vector2D center, Vector2D* vertices, int noOfVertices)
	: VectorShape(center, vertices, noOfVertices)
{
}


GameObject::~GameObject()
{
}

void GameObject::Update(double dTime, vector<GameObject*>& gameObjects, SDL_Window*& window)
{
	this->currentVel = (this->currentVel < this->minVel) ? this->minVel : this->currentVel;
	this->currentVel = (this->currentVel > this->maxVel) ? this->maxVel : this->currentVel;

	this->center = this->center + (this->movementVector * dTime);

	
	// Allows all objects to wrap around the screen,
	// currently based on center which means the bigger the object the more
	// awkward it is, should probably implement some sort of 
	
	int winWidth, winHeight;
	SDL_GetWindowSize(window, &winWidth, &winHeight);

	switch (this->tag)
	{
	case ObjectTags::BULLET:
	{
		if ((this->center.x > winWidth)
			|| (this->center.x < 0)
			|| (this->center.y > winHeight)
			|| (this->center.y < 0))
		{
			gameObjects.erase(gameObjects.begin()+this->handle);
			delete this;
		}
		break;
	}
	case ObjectTags::ASTEROID:
	case ObjectTags::PLAYER:
	{
		this->center.x = (this->center.x > winWidth) ? 0 : this->center.x;
		this->center.x = (this->center.x < 0) ? winWidth : this->center.x;

		this->center.y = (this->center.y > winHeight) ? 0: this->center.y;
		this->center.y = (this->center.y < 0) ? winHeight : this->center.y;
		break;
	}
	}
}

int GameObject::GetProximity()
{
	return this->proximity;
}

bool GameObject::AmIColliding(GameObject * otherObject)
{
	/*
	for every game object in the vector
		check whether the objects are within range using circle collision
		if the object is within range start SAT
			get all edges for the object
			find normals for all of the edges of the object
			for every normal
			for all of the vertices for one objects
			find the projection vector onto the normal
			find magnitude of projection vector
			if magnitude is greater than current max
			it is the new max
			if magnitude is lower than current min
			it is the new min
	do above loop for the second object

	if the max for this object is less than the min for other object
	OR the min for this object is less than the max for other
	*/

    // point in circle check
    // is the objects center within this objects proximity range?
    // (x - center x of circle)^2 + (y - center y of circle)^2 <= radius of circle^2
	if ((pow((otherObject->center.x - this->center.x), 2) + pow((otherObject->center.y - this->center.y), 2))
		<= pow(this->GetProximity(), 2))
	{
		// START SAT COLLISION
		vector<Vector2D> thisObjectEdges = this->GetVectorEdges();
		vector<Vector2D> otherObjectEdges = otherObject->GetVectorEdges();

		vector<Vector2D> edgeNormals;

		Vector2D minTransVector;
		double minTransAmount = 2000;

		bool collision = true;

		for (Vector2D edge : thisObjectEdges)
		{
			edgeNormals.push_back(edge.GetNormal());
		}
		for (Vector2D edge : otherObjectEdges)
		{
			edgeNormals.push_back(edge.GetNormal());
		}


		for (Vector2D normal : edgeNormals)
		{
			// the max scalar value representing the projection
			// in terms of the normal for this object
			double thisObjProjMax = 0;
			// the min scalar value representing the projection
			// in terms of the normal for this object
			double thisObjProjMin = 2000;
			// the max scalar value representing the projection
			// in terms of the normal for the other object
			double otherObjProjMax = 0;
			// the min scalar value representing the projection
			// in terms of the normal for the other object
			double otherObjProjMin = 2000;

			for (Vector2D vertex : this->GetWorldCoords())
			{
				Vector2D projectedVector = normal.GetProjection(vertex);
				double projMag = projectedVector.GetMagnitude();

				thisObjProjMax = (projMag > thisObjProjMax) ? projMag : thisObjProjMax;
				thisObjProjMin = (projMag < thisObjProjMin) ? projMag : thisObjProjMin;
			}
			for (Vector2D vertex : otherObject->GetWorldCoords())
			{
				Vector2D projectedVector = normal.GetProjection(vertex);
				double projMag = projectedVector.GetMagnitude();

				otherObjProjMax = (projMag > otherObjProjMax) ? projMag : otherObjProjMax;
				otherObjProjMin = (projMag < otherObjProjMin) ? projMag : otherObjProjMin;
			}

			// TODO: Fix the minimum translation vector!!!!
			// finding the Minimum Translation Vector for this normal
			/*double newMinTransAmount = (otherObjProjMax - thisObjProjMin < thisObjProjMax - otherObjProjMin) ?
			otherObjProjMax - thisObjProjMin : thisObjProjMax - otherObjProjMin;
			if (newMinTransAmount < minTransAmount)
			{
			minTransAmount = newMinTransAmount;
			minTransVector = normal * newMinTransAmount;
			}*/


			// check for no overlap between the projections
			if (!((thisObjProjMax >= otherObjProjMin) && (otherObjProjMax >= thisObjProjMin)))
			{
				OutputDebugString(L"No Collision Detected!!! \n");
				collision = false;
				break;
			}
		}

		// if there was collision, then offset self out of the other object
		/*if (collision)
		{
		this->Offset(minTransVector.x, minTransVector.y);
		}*/

		return collision;
	}

	return false;
}
