// 0x801BCF0C (64 bytes)
// TArray<EVec3, TArrayDefaultAllocator>::~TArray(void)

template<typename T, typename Allocator>
class TArray {
public:
    ~TArray();
private:
    T* m_data;
    int m_count;
    int m_capacity;
};

class EVec3 {};
class TArrayDefaultAllocator {};

template<>
TArray<EVec3, TArrayDefaultAllocator>::~TArray() {
    // Deallocates the array if data exists
    if (m_data) {
        // Deallocation logic
        m_data = nullptr;
    }
    m_count = 0;
    m_capacity = 0;
}
