#include "Memory.h"
#include <iostream>

using namespace std;

hop::MemoryTracker hop::g_memoryTracker;

void* operator new (size_t size) {
	void* p = malloc(size);

	hop::g_memoryTracker.Add(p, size);

	return p;
}
void operator delete (void* address, size_t size) {
	hop::g_memoryTracker.remove(address, size);
	free(address);
}

namespace hop
{
	void MemoryTracker::Add(void* address, size_t size)
	{
		m_bytesAllocated += size;
		m_numAllocations++;
	}

	void MemoryTracker::remove(void* address, size_t size)
	{
		m_bytesAllocated -= size;
		m_numAllocations--;
	}

	void MemoryTracker::DisplayInfo()
	{
		cout << "current bytes allocated: " << m_bytesAllocated << endl;
		cout << "current number allocations: " << m_numAllocations << endl;
	}
}