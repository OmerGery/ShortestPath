#include <iostream>
#include "minArray.h"

namespace AlgoGraph
{

	minArray::minArray(DynamicArray<Weight> Degrees, int size) : minDegreeArray(size), AccessArray(size+1)
	{
		AccessArray.set_logic_size(size + 1);
		//building initial minArrayDegree from D[v]
		for (int i = 0; i < size; i++)
		{
			AccessArray[i + 1] = i;
			VertexDV ToBeAdded;
			ToBeAdded.Vertex = i+1;
			ToBeAdded.VertexWeight = Degrees[i+1];
			minDegreeArray.push_back(ToBeAdded);
		}

		minDegreeVertex = minDegreeArray[0]; // initial state only origin vertex is 0 and all else in infinity
	}

	int minArray::findMinIndex()
	{
		int size = minDegreeArray.size();
		int minResult = 0;
		for (int i = 0; i < size; i++)
		{
			if (minDegreeArray[i] < minDegreeVertex)
			{
				minDegreeVertex = minDegreeArray[i];
				minResult = i;
			}
		}
		return minResult;
	}

	VertexDV minArray::DeleteMin()
	{
		int indexToDelete = findMinIndex();
		VertexDV res = minDegreeArray[indexToDelete];
		minDegreeArray.removeByIndex(indexToDelete);
		int size = minDegreeArray.size();

		int VertexLoc;
		for (int i = 0; i < size; i++) //reorgenize access array because after delete index is not equal to vertex in minArray
		{
			VertexLoc = minDegreeArray[i].Vertex;
			AccessArray[VertexLoc] = i;
		}
		minDegreeVertex.VertexWeight.infinity = true;
		int newIndex = findMinIndex();
		minDegreeVertex = minDegreeArray[newIndex];
		return res;
	}

	void minArray::decreaseKey(int i, float newDegree)
	{
		int index = AccessArray[i];
		minDegreeArray[index].VertexWeight.infinity = false;
		minDegreeArray[index].VertexWeight.weight = newDegree;
	}

	bool minArray::isEmpty()
	{
		return minDegreeArray.size() == 0;
	}

}