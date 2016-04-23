#include "../../Header Files/Systems/Physics.h"


Physics::Physics(SlotMap<GameObject*>& gameObjs)
	: gameObjects(gameObjs)
{
}

Physics::~Physics()
{
}

void Physics::Update(double dTime)
{
	for (size_t index = 0; index < this->gameObjects.Capacity(); index++)
	{
		GameObject* object = this->gameObjects[index];

		if (object == nullptr)
		{
			continue;
		}

		object->rigidBody.position = object->rigidBody.position + (object->rigidBody.velocity * dTime);

		// with this object check collision with all the other objects
		for (size_t index = 0; index < this->gameObjects.Capacity(); index++)
		{
			GameObject* otherObjIndex = this->gameObjects[index];

			if (otherObjIndex == nullptr || object == otherObjIndex)
			{
				continue;
			}
			//for every game object in the vector
			//	check whether the objects are within range using circle collision
			//	if the object is within range start SAT
			//		get all edges for the object
			//		find normals for all of the edges of the object
			//		for every normal
			//			for all of the vertices for one objects
			//				find the projection vector onto the normal
			//				find magnitude of projection vector
			//				if magnitude is greater than current max
			//					it is the new max
			//				if magnitude is lower than current min
			//					it is the new min
			//do above loop for the second object
			//if the max for this object is less than the min for other object
			//OR the min for this object is less than the max for other
			//*/

			// point in circle check
			// to check if objects are close enough to be worth the collision check
			// (x - pos x of circle)^2 + (y - pos y of circle)^2 <= radius of circle^2
			if ((pow((otherObjIndex->rigidBody.position.x - object->rigidBody.position.x), 2) 
				+ pow((otherObjIndex->rigidBody.position.y - object->rigidBody.position.y), 2))
				<= pow(object->rigidBody.proximity, 2))
			{
				// these references are used to shorten the statements below
				// and to avoid rewriting the whole statements
				Mesh2D& objMesh = object->rigidBody.collisionMesh;
				Mesh2D& otherObjMesh = otherObjIndex->rigidBody.collisionMesh;

				// START SAT COLLISION
				vector<Vector2D> objEdges = objMesh.GetVectorEdges();
				vector<Vector2D> otherObjEdges = otherObjMesh.GetVectorEdges();

				vector<Vector2D> edgeNormals;

				for (Vector2D edge : objEdges)
				{
					edgeNormals.push_back(edge.GetNormal());
				}
				for (Vector2D edge : otherObjEdges)
				{
					edgeNormals.push_back(edge.GetNormal());
				}


				for (Vector2D normal : edgeNormals)
				{
					// the max scalar value representing the projection for object
					double objProjMax = 0;
					// the min scalar value representing the projection for object
					double objProjMin = 9999999;
					// the max scalar value representing the projection for other object
					double otherObjProjMax = 0;
					// the min scalar value representing the projection
					// in terms of the normal for the other object
					double otherObjProjMin = 9999999;

					for (Vector2D vertex : objMesh.GetCoordsInSpace(object->rigidBody.position))
					{
						Vector2D projectedVector = normal.GetProjection(vertex);
						double projMag = projectedVector.GetMagnitude();

						objProjMax = (projMag > objProjMax) ? projMag : objProjMax;
						objProjMin = (projMag < objProjMin) ? projMag : objProjMin;
					}
					for (Vector2D vertex : otherObjMesh.GetCoordsInSpace(otherObjIndex->rigidBody.position))
					{
						Vector2D projectedVector = normal.GetProjection(vertex);
						double projMag = projectedVector.GetMagnitude();

						otherObjProjMax = (projMag > otherObjProjMax) ? projMag : otherObjProjMax;
						otherObjProjMin = (projMag < otherObjProjMin) ? projMag : otherObjProjMin;
					}

					// TODO: Find the minimum traslation vector

					// check for no overlap between the projections, if there isn't
					// there is no collision between the objects
					if (!((objProjMax >= otherObjProjMin) && (otherObjProjMax >= objProjMin)))
					{
						break;
					}
				}

				CollisionMsg colMsg = CollisionMsg(object->handle, otherObjIndex->handle);
				this->messageBus->PostMessage(&colMsg);
			}
		}
	}
}

void Physics::HandleMessage(Msg * postedMsg)
{
}