// 0x80149DFC TTabScratchEntry::GetPersonalityVarRef (20b)
struct TTabAdEntry {
    char _pre[4];
    char _pvar[2];
    char _post[10];
};

struct TTabScratchEntry {
    char _hdr[8];
    TTabAdEntry m_ads[1];
};

char *TTabScratchEntry__GetPersonalityVarRef(TTabScratchEntry *self, int index) {
    return self->m_ads[index]._pvar;
}
