/* DlgWrapper::GetTitleWidth(void) const at 0x8007E7A0 (64B) */

struct TitleVtable {
    char pad[0x70];
    short m_vbaseOff;
    void *(*m_getWidthFunc)(void *);
};

struct TitleInner {
    char pad[0x1C];
    TitleVtable *m_vtable;
};

struct TitleMid {
    char pad[0x60];
    TitleInner *m_inner;
};

struct DlgWrapper {
    char pad[0xAC];
    TitleMid *m_mid;

    float GetTitleWidth(void);
};

float DlgWrapper::GetTitleWidth(void) {
    TitleMid *mid = m_mid;
    TitleInner *inner = mid->m_inner;
    TitleVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    void *(*fn)(void *) = vt->m_getWidthFunc;
    void *result = fn((char *)inner + off);
    return *(float *)result;
}
