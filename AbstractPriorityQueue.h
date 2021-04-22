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

	};
}