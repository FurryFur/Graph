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
		ABGraph* pGraph;
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

		// Add vertices to the graph
		// Vertices are simply represented by unique integers starting from 0
		for (int i = 0; i < 3; ++i)
		{
			pGraph->AddVertex();
		}

		// Create links between graph nodes
		pGraph->CreateLink(0, { 1, 2 });
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

TEST_CASE("Depth First Search")
{
	bool bRunWithMatrixGraph = false;
	bool bRunWithAdjListGraph = false;
	while (!bRunWithMatrixGraph || !bRunWithAdjListGraph)
	{
		ABGraph* pGraph;
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

		// Add vertices to the graph
		// Vertices are simply represented by unique integers starting from 0
		for (int i = 0; i < 16; ++i)
		{
			pGraph->AddVertex();
		}

		// Create links between graph nodes
		pGraph->CreateLink(0, { 4 });
		pGraph->CreateLink(1, { 0, 5 });
		pGraph->CreateLink(2, { 1, 6 });
		pGraph->CreateLink(3, { 2, 6 });
		pGraph->CreateLink(4, { 8 });
		pGraph->CreateLink(5, { 0, 4, 8 });
		pGraph->CreateLink(6, { 2, 3, 9, 10, 11 });
		pGraph->CreateLink(7, { 3 });
		pGraph->CreateLink(8, { 9, 12, 13 });
		pGraph->CreateLink(9, { 6, 8, 10 });
		pGraph->CreateLink(10, { 6, 9, 14 });
		pGraph->CreateLink(11, { 6, 7 });
		pGraph->CreateLink(12, { 13 });
		pGraph->CreateLink(13, { 8, 10 });
		pGraph->CreateLink(14, { 15 });
		pGraph->CreateLink(15, { 11 });

		std::vector<size_t> vecVertexList = pGraph->DepthFirstTraversal(0);
		std::vector<size_t> vecExpectedVertexList{ { 0, 4, 8, 9, 6, 2, 1, 5, 3, 10, 14, 15, 11, 7, 12, 13 } };
		REQUIRE(vecVertexList == vecExpectedVertexList);

		// TODO: Test that changing the order of link creation still 
		// results in matching traversals for all types of graphs

		// TODO: Test that running the traversal again results in the same result

		delete pGraph;
	}
}

TEST_CASE("Breadth First Search")
{
	bool bRunWithMatrixGraph = false;
	bool bRunWithAdjListGraph = false;
	while (!bRunWithMatrixGraph || !bRunWithAdjListGraph)
	{
		ABGraph* pGraph;
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

		// Add vertices to the graph
		// Vertices are simply represented by unique integers starting from 0
		for (int i = 0; i < 16; ++i)
		{
			pGraph->AddVertex();
		}

		// Create links between graph nodes
		pGraph->CreateLink(0, { 4 });
		pGraph->CreateLink(1, { 0, 5 });
		pGraph->CreateLink(2, { 1, 6 });
		pGraph->CreateLink(3, { 2, 6 });
		pGraph->CreateLink(4, { 8 });
		pGraph->CreateLink(5, { 0, 4, 8 });
		pGraph->CreateLink(6, { 2, 3, 9, 10, 11 });
		pGraph->CreateLink(7, { 3 });
		pGraph->CreateLink(8, { 9, 12, 13 });
		pGraph->CreateLink(9, { 6, 8, 10 });
		pGraph->CreateLink(10, { 6, 9, 14 });
		pGraph->CreateLink(11, { 6, 7 });
		pGraph->CreateLink(12, { 13 });
		pGraph->CreateLink(13, { 8, 10 });
		pGraph->CreateLink(14, { 15 });
		pGraph->CreateLink(15, { 11 });

		std::vector<size_t> vecVertexList = pGraph->BreadthFirstTraversal(0);
		std::vector<size_t> vecExpectedVertexList{ { 0, 4, 8, 9, 12, 13, 6, 10, 2, 3, 11, 14, 1, 7, 15, 5 } };
		REQUIRE(vecVertexList == vecExpectedVertexList);

		// TODO: Test that changing the order of link creation still 
		// results in matching traversals for all types of graphs

		// TODO: Test that running the traversal again results in the same result

		delete pGraph;
	}
}