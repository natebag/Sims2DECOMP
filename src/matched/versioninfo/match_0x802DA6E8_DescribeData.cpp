// 0x802DA6E8 EA__Allocator__GeneralAllocator__DescribeData (36b)
struct Chunk;

struct GeneralAllocator {
    void DescribeChunk(Chunk* chunk, char* buf, unsigned int size);
    void DescribeData(void* data, char* buf, unsigned int size);
};

void GeneralAllocator::DescribeData(void* data, char* buf, unsigned int size) {
    DescribeChunk((Chunk*)((char*)data - 8), buf, size);
}
