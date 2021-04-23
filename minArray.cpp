#include <iostream>
#include "minArray.h"

namespace AlgoGraph
{

	minArray::minArray(DynamicArray<Weight> Degrees, int size) : minDegreeArray(size)
	{
		for (int i = 1; i <= size; i++)
		{
			VertexDV ToBeAdded;
			ToBeAdded.Vertex = i;
			ToBeAdded.VertexWeight = Degrees[i];
			minDegreeArray.push_back(ToBeAdded);
		}

	}

	int minArray::findMinIndex()
	{
		int size = minDegreeArray.size();
		int minResult = 1;
		for (int i = 2; i <= size; i++)
		{
			if (minDegreeArray[i] < minDegreeArray[minResult])
			{
				minResult = i;
			}
		}
		
		return minResult;
	}


	VertexDV minArray::DeleteMin()
	{
		int indexToDelete = findMinIndex();
		VertexDV res = minDegreeArray[indexToDelete];
		



		return res;
	}
	void minArray::decreaseKey(int i, float newDegree)
	{
		minDegreeArray[i].VertexWeight.infinity = false;
		minDegreeArray[i].VertexWeight.weight = newDegree;
	}

	bool minArray::isEmpty()
	{
		return !(minDegreeArray.size()==0);
	}

}