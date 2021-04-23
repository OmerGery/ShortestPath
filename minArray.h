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
			DynamicArray<int> AccessArray;
			VertexDV minDegreeVertex;
			int findMinIndex();

		public:
			minArray(DynamicArray<Weight> Degrees, int size);
			VertexDV DeleteMin();
			void decreaseKey(int i, float newDegree);
			bool isEmpty();
			minArray(const minArray& other) = delete;
			minArray& operator=(const minArray& other) = delete;

	};
}