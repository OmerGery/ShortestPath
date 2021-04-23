#include "IOManager.h"
using namespace AlgoGraph;
int main(int argc, char* argv[])
{
	int numberOfVertex, pathStartingVertex, pathEndVertex,fileEndIndex,fileStartIndex;
	string inputFileName;
	if (CheckComandArguments(argc))
		inputFileName = argv[1];
	else
		PrintWrongInput();
	if (!CheckInputFileValidity(inputFileName,fileEndIndex))
	{
		cout << "invalid input";
		exit(1);
	}
	ifstream inputFile;
	inputFile.open(inputFileName);

	// we know that the file is valid
	inputFile >> numberOfVertex >> pathStartingVertex >> pathEndVertex;
	if (!firstThreeSelectionAreValid(numberOfVertex, pathStartingVertex, pathEndVertex))
	{
		PrintWrongInput();
	}
	fileStartIndex =(int) inputFile.tellg();
	AdjancencyListGraph ListGraph(inputFile, numberOfVertex, fileStartIndex);
	AdjacencyMatrixGraph MatrixGraph(inputFile, numberOfVertex, fileStartIndex);
	inputFile.close();
	RunAlgorithms(ListGraph, MatrixGraph, pathStartingVertex, pathEndVertex);
	return 0;
}



