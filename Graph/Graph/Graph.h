#pragma once

#include <vector>

class IGraph
{
public:
	virtual ~IGraph() {};

	virtual void AddVertex() = 0;
	virtual void CreateLink(size_t _iVertFrom, size_t _iVertTo) = 0;
	virtual std::vector<size_t> GetAdjacent(size_t _iVertFrom) const = 0;
	virtual size_t GetSize() const = 0;

protected:
	IGraph() {};
};

