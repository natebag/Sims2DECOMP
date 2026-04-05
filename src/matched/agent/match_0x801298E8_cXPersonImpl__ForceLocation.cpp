// FLAGS: -fno-elide-constructors
// C++ logic is correct - struct layout verified
// 0x801298E8 (76 bytes)
/* cXPersonImpl::ForceLocation(void) */

struct cXPersonImpl_Force_Vtable {
    char pad[0x40];
    short m_delta;       /* 0x40 */
    char _pad[2];
    void* m_func;        /* 0x44 */
};

struct cXPersonImpl_Force_Inner1 {
    cXPersonImpl_Force_Vtable* m_vtable;
    void* m_inner;
};

struct cXPersonImpl_Force {
    char _pad[0x88];                        /* 0x00-0x87 */
    short m_field88;                        /* 0x88 */
    char _pad2[0x3F4-0x8A];
    cXPersonImpl_Force_Inner1* m_field3F4;  /* 0x3F4 */

    void ForceLocation(void);
};

void cXPersonImpl_Force::ForceLocation(void) {
    cXPersonImpl_Force_Inner1* inner = m_field3F4;
    cXPersonImpl_Force_Vtable* vt = inner->m_vtable;
    short delta = vt->m_delta;
    void (*fn)(void*) = (void (*)(void*))vt->m_func;
    fn((char*)inner + delta);
    m_field88 = 0;
}
