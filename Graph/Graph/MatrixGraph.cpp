#include "MatrixGraph.h"



CMatrixGraph::CMatrixGraph()
{
}


CMatrixGraph::~CMatrixGraph()
{
}

void CMatrixGraph::AddVertex()
{
	// Add new row to adjacency matrix
	m_matAdjcencies.emplace_back(m_matAdjcencies.size());

	// Add new column to adjacency matrix
	for (auto itRow = m_matAdjcencies.begin(); itRow != m_matAdjcencies.end(); ++itRow)
	{
		itRow->push_back(false);
	}
}

void CMatrixGraph::CreateLink(size_t _szVertFrom, size_t _szVertTo)
{
	m_matAdjcencies.at(_szVertFrom).at(_szVertTo) = true;
}

std::vector<size_t> CMatrixGraph::GetAdjacent(size_t _szVertFrom) const
{
	std::vector<size_t> vecAdjacent;

	std::vector<bool> vecAdjRow = m_matAdjcencies.at(_szVertFrom);
	for (size_t szVert = 0; szVert < vecAdjRow.size(); ++szVert)
	{
		if (vecAdjRow[szVert])
		{
			vecAdjacent.push_back(szVert);
		}
	}

	return vecAdjacent;
}

size_t CMatrixGraph::GetSize() const
{
	// Matrix should be square
	return m_matAdjcencies.size();
}
