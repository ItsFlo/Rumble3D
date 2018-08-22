#pragma once
#include "RigidBody.h"

namespace rum
{
	struct PotentialContacts
	{
		RigidBody* m_bodies[2];
	};
	
	template<class BoundingVolumeClass>
	class BVHNode
	{
	public:
		BVHNode();
		BVHNode(BVHNode<BoundingVolumeClass> * parent,
			const BoundingVolumeClass & volume,
			RigidBody * body = nullptr);
		~BVHNode();

		bool isLeaf() const;
		// Identifiziert die m�glichen Kontakte von diesem Knoten abw�rts
		// im Baum. Diese werden in das array contacts geschrieben (bis
		// Anzahl = limit). R�ckgabe ist die Anzahl der gefundenen Kontakte.
		unsigned int getPotentialContacts(PotentialContacts* contacts, 
										  unsigned int limit) const;
	protected:
		// Gibt true zur�ck, wenn das eigene Volume mit dem Volume von other
		// �berlappt, und false sonst.
		bool overlaps(BVHNode<BoundingVolumeClass> * other) const;
		// Rekursiver Teil des Algorithmus auf den Kindern der Wurzel und 
		// deren Kinder.
		unsigned getPotentialContactsWith(
			BVHNode<BoundingVolumeClass> * other,
			PotentialContacts * contacts,
			unsigned limit) const;
		void recalculateBoundingVolume();
		void insert(RigidBody* newBody, const BoundingVolumeClass &newVolume);

		// Kindknoten dieses Knotens.
		BVHNode* m_children[2];
		// Bounding Volume, das alle Kinder umfasst.
		BoundingVolumeClass m_volume;
		// Festk�rper an diesem Knoten. Nur bei Bl�ttern
		// gesetzt, sonst NULL.
		RigidBody* m_body;
		// Elternknoten im Baum:
		BVHNode* m_parent;
	};
}
