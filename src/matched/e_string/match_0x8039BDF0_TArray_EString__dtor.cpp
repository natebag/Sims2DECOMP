/* TArray<EString, TArrayDefaultAllocator>::~TArray(void) @ 0x8039BDF0 (64 bytes) */

class EString {
public:
    char* m_buffer;
};

class TArray_EString {
public:
    EString* m_data;
    int m_size;
    int m_capacity;
    void Deallocate(void);
    void dtor(int flag);
};

extern void __builtin_delete(void* p);

void TArray_EString::dtor(int flag) {
    Deallocate();
    if (flag & 1) {
        __builtin_delete(this);
    }
}
