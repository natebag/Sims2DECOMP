// 0x8015BEE8 ObjectDataObjDefinition::Reset(void) (72B)

extern void __builtin_delete(void*);

class ObjectDataObjDefinition {
public:
    char pad_00[26];
    unsigned char m_owned;  // 26
    char  pad_1B[1];
    void* m_ptr;            // 28
    void Reset();
};

void ObjectDataObjDefinition::Reset() {
    if (m_owned != 0) {
        __builtin_delete(m_ptr);
        unsigned int z = 0;
        m_ptr = (void*)z;
        m_owned = (unsigned char)z;
    }
}
