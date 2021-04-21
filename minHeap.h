#pragma once 
#include "ConstTypes.h"
#include "GraphEdge.h"
namespace AlgoGraph
{
	class minHeap
	{
		private:
		EdgeWeight** heapArray;
			int maxSize;
			int heapSize;
			int allocated;


		public:
			minHeap(int capacity);
			minHeap(EdgeWeight* tav[], int size);
			~minHeap();
			static int Left(int node);
			static int Right(int left);
			static int Parent(int node);
			void FixHeap(int node);
			EdgeWeight* Min();
			EdgeWeight* DeleteMin();
			void Insert(EdgeWeight* item);
			bool isEmpty();
			void make_empty();

	};
}
