#pragma once 
#include "ConstTypes.h"
#include "GraphEdge.h"
#include "DynamicArray.h"
#include "AbstractPriorityQueue.h"
namespace AlgoGraph
{
	class minArray : public PriorityQueue
	{
	private:

		DynamicArray<VertexDV> minDegreeArray;
		int findMinIndex();

	public:

		minArray(DynamicArray<Weight> Degrees, int size);
		VertexDV DeleteMin();
		void decreaseKey(int i, float newDegree);
		bool isEmpty();

	};
}