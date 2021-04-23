#pragma once 
#include "ConstTypes.h"
#include "GraphEdge.h"
#include "DynamicArray.h"
#include "AbstractPriorityQueue.h"

namespace AlgoGraph 
{
	class minHeap : public PriorityQueue
	{
		private:
			DynamicArray<int> AccessArray;
			VertexDV* heapArray;
			int maxSize;
			int heapSize;
			int allocated;


		public:
			minHeap(int capacity);
			minHeap(DynamicArray<Weight> Degrees, int size);
			~minHeap();
			static int Left(int node);
			static int Right(int left);
			static int Parent(int node);
			void FixHeap(int node);
			VertexDV Min();
			void Insert(VertexDV item);
			bool isEmpty();
			void make_empty();
			void decreaseKey(int i, float newDegree);
			VertexDV DeleteMin();
	};
}
