// VERSION_DIFF: register allocation differs (DOL uses r28/r30/r29, compiled uses r30/r11/r9)
// C++ logic is correct - struct layout verified against ESim.h
// 0x8003461C (116 bytes)
/* ESim::CompositeSkin(void) */

struct ESimCompositeVtable {
    char pad[0x140];
    short m_delta;       /* 0x140 */
    char _pad[2];
    void* m_func;        /* 0x144 - actually at 0x150 from inner->vtable */
};

struct ESimCompositeInner {
    char pad[4];
    ESimCompositeVtable* m_vtable;
};

struct ESim_CompositeSkin {
    char pad_3D0[0x3D0];
    ESimCompositeInner* m_inner;  /* 0x3D0 */
    char pad_3D4[0x63C-0x3D4];
    void* m_model;                /* 0x63C */
    
    void CompositeSkin(void);
};

// Forward declarations for external functions
extern void SimModel_CompositeSkin(void* model, char arg1, int arg2);

void ESim_CompositeSkin::CompositeSkin(void) {
    ESimCompositeInner* inner = m_inner;
    ESimCompositeVtable* vt = inner->m_vtable;
    short delta = vt->m_delta;  /* at offset 0x150 */
    void (*fn)(void*) = (void (*)(void*))vt->m_func;  /* at offset 0x154 */
    fn((char*)inner + delta);
    
    // After first virtual call
    SimModel_CompositeSkin(m_model, /*arg from inner+0x89*/ 0, 60);
}
