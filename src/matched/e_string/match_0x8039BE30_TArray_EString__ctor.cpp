/* TArray<EString, TArrayDefaultAllocator>::TArray(void) @ 0x8039BE30 (48 bytes) */

class EString {
public:
    char* m_buffer;
};

class TArray_EString {
public:
    EString* m_data;
    int m_size;
    int m_capacity;
    void Init(void);
    TArray_EString(void);
};

TArray_EString::TArray_EString(void) {
    Init();
}
