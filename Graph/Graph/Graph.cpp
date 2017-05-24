#include <stack>
#include <vector>
#include <queue>

#include "Graph.h"

void ABGraph::CreateLink(size_t _szVertFrom, std::initializer_list<size_t> _szVertsTo)
{
	for (auto itVert = _szVertsTo.begin(); itVert != _szVertsTo.end(); ++itVert)
	{
		CreateLink(_szVertFrom, *itVert);
	}
}

std::vector<size_t> ABGraph::DepthFirstTraversal(size_t _szVertStart) const
{
	std::vector<size_t> vecTraversalResult;
	std::vector<bool> vecIsVisited(GetSize());
	std::stack<size_t> fringe;

	// Add starting vertex to the fringe
	fringe.push(_szVertStart);

	while (!fringe.empty())
	{
		// Get next vertex to explore
		size_t szCurVert = fringe.top();
		fringe.pop();

		// Make sure we haven't already visited this vertex
		if (!vecIsVisited.at(szCurVert))
		{
			// Mark vertex as visited
			vecIsVisited.at(szCurVert) = true;

			// Add vertex to the resulting traversal list
			vecTraversalResult.push_back(szCurVert);

			// Add adjacent unvisited vertices to the fringe
			std::vector<size_t> vecAdjacent = GetAdjacent(szCurVert);
			for (auto itAdj = vecAdjacent.rbegin(); itAdj != vecAdjacent.rend(); ++itAdj)
			{
				if (!vecIsVisited.at(*itAdj))
				{
					fringe.push(*itAdj);
				}
			}
		}
	}

	return vecTraversalResult;
}

std::vector<size_t> ABGraph::BreadthFirstTraversal(size_t _szVertStart) const
{
	std::vector<size_t> vecTraversalResult;
	std::vector<bool> vecIsVisited(GetSize());
	std::queue<size_t> fringe;

	// Add starting vertex to the fringe
	fringe.push(_szVertStart);

	while (!fringe.empty())
	{
		// Get next vertex to explore
		size_t szCurVert = fringe.front();
		fringe.pop();

		// Make sure we haven't already visited this vertex
		if (!vecIsVisited.at(szCurVert))
		{
			// Mark vertex as visited
			vecIsVisited.at(szCurVert) = true;

			// Add vertex to the resulting traversal list
			vecTraversalResult.push_back(szCurVert);

			// Add adjacent unvisited vertices to the fringe
			std::vector<size_t> vecAdjacent = GetAdjacent(szCurVert);
			for (auto itAdj = vecAdjacent.begin(); itAdj != vecAdjacent.end(); ++itAdj)
			{
				if (!vecIsVisited.at(*itAdj))
				{
					fringe.push(*itAdj);
				}
			}
		}
	}

	return vecTraversalResult;
}
