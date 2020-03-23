#ifndef MEMORY_H
#define MEMORY_H
#include <vector>

class memory{
	std::vector<int>registries;
public:
	void set(unsigned long,int);
	int get(unsigned long) const;
};

#endif /* MEMORY_H */
