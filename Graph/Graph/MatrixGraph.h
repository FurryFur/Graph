#pragma once
#include "Graph.h"
class CMatrixGraph : public IGraph
{
public:
	CMatrixGraph();
	virtual ~CMatrixGraph() override;

	// Inherited via IGraph
	virtual void AddVertex() override;
	virtual void CreateLink(size_t _iVertFrom, size_t _iVertTo) override;
	virtual std::vector<size_t> GetAdjacent(size_t _iVertFrom) const override;
	virtual size_t GetSize() const override;

private:
	std::vector<std::vector<bool>> m_matAdjcencies;
};

