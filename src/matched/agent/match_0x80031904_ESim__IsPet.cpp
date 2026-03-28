/* ESim::IsPet(void) at 0x80031904 (56B) */

struct ESimPetVtable {
    char pad[0x1F0];
    short m_vbaseOff;
    int (*m_isPetFunc)(void *);
};

struct ESimPetInner {
    char pad[0x04];
    ESimPetVtable *m_vtable;
};

struct ESim_IsPet {
    char pad[0x3D0];
    ESimPetInner *m_inner;

    int IsPet(void);
};

int ESim_IsPet::IsPet(void) {
    ESimPetInner *inner = m_inner;
    ESimPetVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_isPetFunc;
    return fn((char *)inner + off);
}
