#include "minHeap.h"
#include <iostream>

namespace AlgoGraph
{
	minHeap::minHeap(int capacity)
	{
		heapArray = new VertexDV[capacity];
		maxSize = capacity;
		heapSize = 0;
		allocated = 1; //allocation has been made here- only give is size of array from user
	}

	//Building minimum heap with floyd algorithem
	minHeap::minHeap(DynamicArray<Weight> Degrees, int size) : AccessArray(size+1)
	{
		heapSize = size;
		maxSize = size;
		heapArray = new VertexDV[size];
		AccessArray.set_logic_size(size+1);

		for (int i = 0; i < size; i++)
		{
			heapArray[i].VertexWeight = Degrees[i+1];
			heapArray[i].Vertex = i+1;
			AccessArray[i + 1] = i; //places the index location of vertex in heapArray
		}

		allocated = 1; 
		int n = (size / 2) - 1;
		for (int i = n; i >= 0; i--)
			FixHeap(i);
	}
	minHeap::~minHeap()
	{
		if (allocated)
			delete[] heapArray;
		heapArray = nullptr;
	}
	int minHeap::Left(int i)
	{
		return(2 * i + 1);
	}
	int minHeap::Right(int i)
	{
		return(2 * i + 2);
	}
	int minHeap::Parent(int i)
	{
		return ((i - 1) / 2);
	}

	void Swap(VertexDV* a, VertexDV* b)
	{
		VertexDV temp = *a;
		*a = *b;
		*b = temp;
	}
	void Swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void minHeap::FixHeap(int i)
	{
		int min =i;
		int left = Left(i);
		int right = Right(i);


		if (left < heapSize && heapArray[left] < heapArray[i])
			min = left;
		else min = i;
		if (right < heapSize && heapArray[right] < heapArray[min])
			min = right;

		if (min != i)
		{
			int VertexA = (heapArray + i)->Vertex;
			int VertexB = (heapArray + min)->Vertex;
			Swap(heapArray+i, heapArray+min);
			Swap(&AccessArray[VertexA], &AccessArray[VertexB]);
			FixHeap(min);
		}
	}

	// Decreases value of VertexDecree located in position i in heapArray.
	// assumming that  newDegree is smaller than the old one.
	void minHeap::decreaseKey(int Vertex, float newDegree)
	{
		int i = AccessArray[Vertex];
		heapArray[i].VertexWeight.infinity = false;
		heapArray[i].VertexWeight.weight = newDegree;
		while (i != 0 && heapArray[i] < heapArray[Parent(i)])
		{
			int accessParent = heapArray[Parent(i)].Vertex;
			Swap(&heapArray[i], &heapArray[Parent(i)]);
			Swap(&AccessArray[Vertex], &AccessArray[accessParent]);
			i = Parent(i);
		}
	}


	VertexDV minHeap::Min()
	{
		return heapArray[0];
	}
	VertexDV minHeap::DeleteMin()
	{
		if (heapSize < 1)
			throw "There is no min to return because the heap is empty";
		else
		{
			VertexDV min = heapArray[0];
			heapSize--;
			heapArray[0] = heapArray[heapSize];
			int VertexWentToZero = heapArray[0].Vertex;
			AccessArray[VertexWentToZero] = 0;
			FixHeap(0);

			return min;
		}
	}

	void minHeap::Insert(VertexDV item)
	{
		if (heapSize == maxSize)
			throw "The heap is full, cant insert more";
		if (item.VertexWeight.infinity)
		{
			heapArray[heapSize] = item;
			heapSize++;
		}
		else
		{
			int i = heapSize;
			heapSize++;
			while ((i > 0) && (heapArray[Parent(i)].VertexWeight.weight > item.VertexWeight.weight))
			{
				heapArray[i] = heapArray[Parent(i)];
				i = Parent(i);
			}
			heapArray[i] = item;
		}

	}

	bool minHeap::isEmpty()
	{
		return !heapSize; //if heapsize>0 will return false- not empty, otherwise will return true- empty
	}

	void minHeap::make_empty()
	{
		heapSize = 0;
	}

}