// this is a Priority Queue abstract class, holds the common methods for the queue data structures 
#pragma once
#include "GraphEdge.h"
#include <iostream>

using namespace std;
namespace AlgoGraph
{
	class PriorityQueue
	{
	public:
		virtual VertexDV DeleteMin() = 0;
		virtual void decreaseKey(int i, float newDegree) = 0;
		virtual bool isEmpty() = 0;
		PriorityQueue& operator=(const PriorityQueue& other) = delete;
	};
}