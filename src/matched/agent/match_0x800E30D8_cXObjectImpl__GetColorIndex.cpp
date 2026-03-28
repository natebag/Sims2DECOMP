/* cXObjectImpl::GetColorIndex(void) const at 0x800E30D8 (64B) */

struct ColorVtable {
    char pad[0x260];
    short m_vbaseOff;
    int (*m_getColorFunc)(void *, int);
};

struct ColorInner {
    char pad[0x04];
    ColorVtable *m_vtable;
};

struct cXObjectImplCI {
    char pad[0x04];
    ColorInner *m_inner;

    unsigned char GetColorIndex(void);
};

unsigned char cXObjectImplCI::GetColorIndex(void) {
    ColorInner *inner = m_inner;
    ColorVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, int) = vt->m_getColorFunc;
    return (unsigned char)fn((char *)inner + off, 55);
}
