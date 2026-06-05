// 0x80285F30 AptArray::_reserve(int) (188B) — clean
//
// Grows the backing store to hold at least n elements. Rounds n up to the next
// power of two (min 8), allocates+zeroes a new slot array from the value pool,
// copies the old contents over, frees the old array, and stores the new pointer
// and capacity. No-op when the current capacity already suffices.

struct AptValuePool {
    void* Allocate(unsigned int size);             // @0x802B5848
    void  Deallocate(void* p, unsigned int size);  // @0x802B598C
};
extern AptValuePool* g_aptValuePool;   // SDA -0x59ec

extern "C" void* memset(void* p, int c, unsigned int n);          // @0x802435E4
extern "C" void* memcpy(void* d, const void* s, unsigned int n, ...);  // @0x80243454

struct AptArray {
    char  pad[0x24];   // 0x00 .. 0x23
    void** m_data;     // 0x24
    int   m_capacity;  // 0x28
    void  _reserve(int n);
};

void AptArray::_reserve(int n) {
    int cap = 0;
    if (m_capacity < n) {
        n = n - 1;
        if (n != 0) {
            do {
                cap++;
                n = n >> 1;
            } while (n != 0);
        }
        cap = 1 << cap;
        cap = cap < 8 ? 8 : cap;
        int bytes = cap * 4;
        void* newdata = g_aptValuePool->Allocate(bytes);
        memset(newdata, 0, bytes);
        if (m_data != 0) {
            memcpy(newdata, m_data, m_capacity * 4);
            g_aptValuePool->Deallocate(m_data, m_capacity * 4);
        }
        m_data = (void**)newdata;
        m_capacity = cap;
    }
}
