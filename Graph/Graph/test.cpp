#include <algorithm>
#include "catch.hpp"
#include "Graph.h"
#include "MatrixGraph.h"
#include "AdjListGraph.h"

TEST_CASE("Test Constructing Graph")
{
	bool bRunWithMatrixGraph = false;
	bool bRunWithAdjListGraph = false;
	while (!bRunWithMatrixGraph || !bRunWithAdjListGraph)
	{
		IGraph* pGraph;
		if (!bRunWithMatrixGraph)
		{
			pGraph = new CMatrixGraph;
			bRunWithMatrixGraph = true;
		}
		else
		{
			pGraph = new CAdjListGraph;
			bRunWithAdjListGraph = true;
		}

		// Add 8 vertices to the graph
		// Vertices are simply represented by unique integers starting from 0
		for (int i = 0; i < 3; ++i)
		{
			pGraph->AddVertex();
		}

		// Create links between graph nodes
		pGraph->CreateLink(0, 1);
		pGraph->CreateLink(0, 2);
		pGraph->CreateLink(1, 0);
		pGraph->CreateLink(1, 2);

		// Creating duplicate links shouldn't do anything
		pGraph->CreateLink(0, 1);

		// Should return a list of vertices accessable from the specified vertex
		std::vector<size_t> vecszVerticesAdj = pGraph->GetAdjacent(0);
		std::vector<size_t> vecszVerticesAdjExpected = { 1, 2 };
		REQUIRE(vecszVerticesAdj == vecszVerticesAdjExpected);
		vecszVerticesAdj = pGraph->GetAdjacent(1);
		vecszVerticesAdjExpected = { 0, 2 };
		REQUIRE(vecszVerticesAdj == vecszVerticesAdjExpected);
		vecszVerticesAdj = pGraph->GetAdjacent(2);
		vecszVerticesAdjExpected = {};
		REQUIRE(vecszVerticesAdj == vecszVerticesAdjExpected);

		// Check size of graph is as expected
		REQUIRE(pGraph->GetSize() == 3);

		delete pGraph;
	}
}