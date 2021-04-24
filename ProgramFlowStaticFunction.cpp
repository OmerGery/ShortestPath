#include <iostream>
#include <fstream>
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "GraphAlgorithms.h"
#include <chrono>
#include <iomanip>
#include "ProgramFlowStaticFunction.h"
#define MAX_CHARS_INLINE 512
namespace AlgoGraph
{
	bool CheckInputFileValidity(string i_inputFileName, int& amountOfEdges)
	{
		ifstream inputFile;
		inputFile.open(i_inputFileName);
		char* line = nullptr;
		char currentChar;
		amountOfEdges = 0;
		for (int i = 0; i < 3; i++)
		{
			int k = 0;
			inputFile.getline(line, MAX_CHARS_INLINE);
			currentChar = line[k];
			while (currentChar != '\0')
			{
				if (currentChar > '9' || currentChar < '0')
					return false;
				currentChar = line[k];
				k++;
			}

		}
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

	void PrintWrongInput()
	{
		cout << "invalid input";
		exit(1);
	}

	bool CheckComandArguments(int argc)
	{
		return argc == 3;
	}

	void GetFileNames(int argc, char* argv[],string& inputFileName,string& outputFileName)
	{
		if (CheckComandArguments(argc))
			inputFileName = argv[1];
		else
			PrintWrongInput();
		int amountOfEdges;
		if (!CheckInputFileValidity(inputFileName,amountOfEdges))
			PrintWrongInput();
		inputFileName = argv[1];
		outputFileName = argv[2];
	}

	void GetOriginVariables(int& NumberOfVertices, int& OriginVertex, int& EndVertex, int& FileIndentation, string FileName)
	{
		ifstream inputFile;
		inputFile.open(FileName);
		
		// we know that the file is valid
		inputFile >> NumberOfVertices;
		inputFile >> OriginVertex;
		inputFile >> EndVertex;
		if (!firstThreeSelectionAreValid(NumberOfVertices, OriginVertex, EndVertex))
			PrintWrongInput();
		FileIndentation = (int)inputFile.tellg();
		inputFile.close();

	}
	std::chrono::steady_clock::time_point StartTimer()
	{
		std::chrono::steady_clock::time_point start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);
		return start;
	}
	void EndTimer(ofstream& fileName, std::chrono::steady_clock::time_point start,const char* FuncName)
	{
		auto end = chrono::high_resolution_clock::now();
		double time_taken = (double)chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		fileName << FuncName << " <" << fixed << time_taken << setprecision(9);
		fileName << "> sec" << endl;
	}
	void RunBelmanFordMatrix(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile)
	{
		auto start = StartTimer();
		float ShortestMatrixPath;

		Result PathOfAdjacencyMatrixGraph = GraphAlgorithms::BellmanFord(&MatrixImplementedGraph, OriginVertex, EndVertex, ShortestMatrixPath);

		if (PathOfAdjacencyMatrixGraph == Result::SUCCESS)
			cout << "Matrix Bellman Ford " << ShortestMatrixPath << endl;
		else if ((PathOfAdjacencyMatrixGraph == Result::NEGATIVE_CYCLE))
			cout << "Matrix Bellman Ford: There is a Negative Cycle in the graph" << endl;
		else 
			cout << "Matrix Bellman Ford: No route from " << OriginVertex << " to " << EndVertex << endl;
		EndTimer(outputFile,start, "Matrix Bellman Ford" );
	}
	void RunBelmanFordList(AdjancencyListGraph& listImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile)
	{
		auto start = StartTimer();
		float ShortestListPath;
		Result PathOfListGraph = GraphAlgorithms::BellmanFord(&listImplementedGraph, OriginVertex, EndVertex, ShortestListPath);
		if (PathOfListGraph == Result::SUCCESS)
			cout << "Adjacency Bellman Ford " << ShortestListPath << endl;
		else if ((PathOfListGraph == Result::NEGATIVE_CYCLE))
			cout << "Adjacency Bellman Ford: There is a Negative Cycle in the graph" << endl;
		else
			cout << "Adjacency Bellman Ford: No route from " << OriginVertex << " to " << EndVertex << endl;
		EndTimer(outputFile, start, "Adjacency Bellman Ford");
	}
	void RunHeapMatrixDijkstra(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile )
	{
		auto start = StartTimer();
		float ShortestMatrixPath;
		if (GraphAlgorithms::DijkstraHeap(&MatrixImplementedGraph, OriginVertex, EndVertex, ShortestMatrixPath))
		{
			cout << "Matrix Dijkstra heap: No Route from " << OriginVertex << " to " << EndVertex << endl;
		}
		else cout << "Matrix Dijkstra heap " << ShortestMatrixPath << endl;
		EndTimer(outputFile, start, "Matrix Dijkstra heap:");
	}
	void RunHeapListDijkstra(AdjancencyListGraph& ListImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile)
	{
		auto start = StartTimer();
		float ShortestListPath;
		if (GraphAlgorithms::DijkstraHeap(&ListImplementedGraph, OriginVertex, EndVertex, ShortestListPath))
		{
			cout << "Adjacency Dijkstra heap: No Route from " << OriginVertex << " to " << EndVertex << endl;
		}
		else cout << "Adjacency Dijkstra heap " << ShortestListPath << endl;
		EndTimer(outputFile, start, "Adjacency Dijkstra heap");
	}

	void RunArrayMatrixDijkstra(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile)
	{
		auto start = StartTimer();
		float ShortestMatrixPath;
		if (GraphAlgorithms::DijkstraArray(&MatrixImplementedGraph, OriginVertex, EndVertex, ShortestMatrixPath))
		{
			cout << "Matrix Dijkstra array: No Route from " << OriginVertex << " to " << EndVertex << endl;
		}
		else cout << "Matrix Dijkstra array " << ShortestMatrixPath << endl;
		EndTimer(outputFile, start, "Matrix Dijkstra array");
	}
	void RunArrayListDijkstra(AdjancencyListGraph& ListImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile)
	{
		auto start = StartTimer();
		float ShortestListPath;

		if (GraphAlgorithms::DijkstraArray(&ListImplementedGraph, OriginVertex, EndVertex, ShortestListPath))
		{
			cout << "Adjacency Dijkstra array: No Route from " << OriginVertex << " to " << EndVertex << endl;
		}
		else cout << "Adjacency Dijkstra array " << ShortestListPath << endl;
		EndTimer(outputFile, start, "Adjacency Dijkstra array");
	}
}


