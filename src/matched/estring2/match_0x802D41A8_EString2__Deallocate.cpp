/* EString2::Deallocate(unsigned wchar_t *) @ 0x802D41A8 (80 bytes) */

typedef unsigned short wchar_t_u;

extern char _estring2Null[2];
extern char _estring2Error[];

class EAHeap;
extern EAHeap* MainHeap();
extern void EAHeap_Free(EAHeap*, void*);

struct EString2_DEA {
    wchar_t_u *m_str;
    void Deallocate(wchar_t_u *p);
};

void EString2_DEA::Deallocate(wchar_t_u *p) {
    if (p == (wchar_t_u*)_estring2Null) return;
    if (p == (wchar_t_u*)_estring2Error) return;
    EAHeap_Free(MainHeap(), p);
}
