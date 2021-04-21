#pragma once 
#include "ConstTypes.h"
#include "GraphEdge.h"
namespace AlgoGraph
{
	class minHeap
	{
		private:
			Weight* heapArray;
			int maxSize;
			int heapSize;
			int allocated;


		public:
			minHeap(int capacity);
			minHeap(Weight Degrees[], int size);
			~minHeap();
			static int Left(int node);
			static int Right(int left);
			static int Parent(int node);
			void FixHeap(int node);
			Weight Min();
			Weight DeleteMin();
			void Insert(Weight item);
			bool isEmpty();
			void make_empty();

	};
}
