#include "IOManager.h"
#include <iostream>
using namespace std;
namespace AlgoGraph
{
	bool CheckInputFileValidity(string i_inputFileName, int& endLocation)
	{
		ifstream inputFile;
		inputFile.open(i_inputFileName);
		string line;
		char currentChar;
		endLocation = 0;
		for (int i = 0; i < 3; i++)
		{
			currentChar = inputFile.get();
			endLocation++;
			if (currentChar > '9' || currentChar < '1')
				return false;
			while (currentChar != '\n')
			{
				if (currentChar > '9' || currentChar < '0')
				{
					return false;
				}
				currentChar = inputFile.get();
				endLocation++;
			}
		}
		int numbers = 0;
		bool lastWasSpace = false;
		bool optionForPoint = false;
		bool onlySpaces = false;
		int placeInLine = 0;
		while (!inputFile.eof())
		{
			getline(inputFile, line);
			currentChar = line[placeInLine];
			placeInLine++;
			endLocation++;
			if (currentChar > '9' || currentChar < '1')
				return false;
			while (currentChar != '\n')
			{
				if (currentChar == ' ')
				{
					if (lastWasSpace)
						return false;
					lastWasSpace = true;
					numbers++;
					if (numbers == 2)
						optionForPoint = true;
				}
				else if (currentChar > '9' || currentChar < '0')
				{
					return false;
				}
				else
				{
					lastWasSpace = false;
				}

				if (numbers == 2)
				{
					if (optionForPoint)
					{
						optionForPoint = false;
						if (currentChar > '9' || currentChar < '0')
						{
							if (currentChar != '.')
								return false;
						}
					}
					numbers++;
				}
				if (numbers == 3)
				{
					if (currentChar != '\t' && currentChar != ' ' && currentChar)
						if (currentChar != '\n')
							return false;
				}
			}
		}
		inputFile.close();
		return true;
	}
	bool firstThreeSelectionAreValid(int numberOfVertex, int pathStartingVertex, int pathEndVertex)
	{
		if (numberOfVertex < 0)
			return false;
		if (pathStartingVertex > numberOfVertex || pathStartingVertex < 1)
			return false;
		if (pathEndVertex > numberOfVertex || pathEndVertex < 1)
			return false;
		return true;
	}
	bool CheckComandArguments(int argc)
	{
		return argc == 2;
	}
	void PrintWrongInput()
	{
		cout << "invalid input";
		exit(1);
	}
	void RunAlgorithms(AdjancencyListGraph& ListGraph, AdjacencyMatrixGraph& MatrixGraph, int pathStartingVertex, int pathEndVertex)
	{
		float matrixpath, listpath, dijkstraHeapPath;
		if (GraphAlgorithms::DijkstraHeap(&ListGraph, pathStartingVertex, pathEndVertex, dijkstraHeapPath))
		{
			cout << "Adjacency Dijkstra heap: there is no path from the selected vertex to the selected end vertex" << endl;
		}
		else cout << "Adjacency Dijkstra heap " << dijkstraHeapPath << endl;
		if (GraphAlgorithms::DijkstraArray(&ListGraph, pathStartingVertex, pathEndVertex, dijkstraHeapPath))
		{
			cout << "Adjacency Dijkstra array: there is no path from the selected vertex to the selected end vertex" << endl;
		}
		else cout << "Adjacency Dijkstra array " << dijkstraHeapPath << endl;
		Result PathOfAdjancencyListGraph = GraphAlgorithms::BellmanFord(&ListGraph, pathStartingVertex, pathEndVertex, listpath);
		switch (PathOfAdjancencyListGraph)
		{
		case Result::NEGATIVE_CYCLE:
		{
			cout << "Adjacency Bellman Ford: there is a negative cycle in the grap" << endl;
			break;
		}
		case Result::INFINITY_PATH:
		{
			cout << "Adjacency Bellman Ford: there is no path from the selected vertex to the selected end vertex" << endl;
			break;
		}
		default:
		{
			cout << "Adjacency Bellman Ford " << listpath << endl;
		}
		}

		if (GraphAlgorithms::DijkstraHeap(&MatrixGraph, pathStartingVertex, pathEndVertex, dijkstraHeapPath))
		{
			cout << "Matrix Dijkstra heap: there is no path from the selected vertex to the selected end vertex" << endl;
		}
		else cout << "Matrix Dijkstra heap " << dijkstraHeapPath << endl;

		if (GraphAlgorithms::DijkstraArray(&MatrixGraph, pathStartingVertex, pathEndVertex, dijkstraHeapPath))
		{
			cout << "Matrix Dijkstra array: there is no path from the selected vertex to the selected end vertex" << endl;
		}
		else cout << "Matrix Dijkstra array " << dijkstraHeapPath << endl;

		Result PathOfAdjacencyMatrixGraph = GraphAlgorithms::BellmanFord(&MatrixGraph, pathStartingVertex, pathEndVertex, matrixpath);

		switch (PathOfAdjacencyMatrixGraph)
		{
		case Result::NEGATIVE_CYCLE:
		{
			cout << "Matrix Bellman Ford: there is a negative cycle in the grap" << endl;
			break;
		}
		case Result::INFINITY_PATH:
		{
			cout << "Matrix Bellman Ford: there is no path from the selected vertex to the selected end vertex" << endl;
			break;
		}
		default:
		{
			cout << "Matrix Bellman Ford " << listpath << endl;
		}
		}
	}
}