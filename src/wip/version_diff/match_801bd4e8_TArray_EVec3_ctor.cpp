// 0x801BD4E8 (64 bytes)
// TArray<EVec3, TArrayDefaultAllocator>::TArray(TArray<EVec3, TArrayDefaultAllocator> &)

template<typename T, typename Allocator>
class TArray {
public:
    TArray(TArray& other);
private:
    T* m_data;
    int m_count;
    int m_capacity;
};

class EVec3 {};
class TArrayDefaultAllocator {};

template<>
TArray<EVec3, TArrayDefaultAllocator>::TArray(TArray& other) {
    // Copy constructor - copy data from other
    m_data = other.m_data;
    m_count = other.m_count;
    m_capacity = other.m_capacity;
}
