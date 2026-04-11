// VERSION_DIFF: SDA global access pattern differs
// C++ logic is correct
// 0x802B5DC4 (80 bytes)
/* AptPrototype::RegisterReferences(void) const */

// Forward declarations
extern void AptPrototype_Register(void* self);  /* 0x802B4180 */
extern void (*g_registerFunc)(void*, const char*);  /* SDA -27024 */

struct AptPrototype_RegisterRefs {
    char _pad[0x20];
    void* m_field20;  /* 0x20 */
    
    void RegisterReferences(void) const;
};

void AptPrototype_RegisterRefs::RegisterReferences(void) const {
    AptPrototype_Register((void*)this);
    if (m_field20 != 0) {
        g_registerFunc((void*)this, "prototype");
    }
}
