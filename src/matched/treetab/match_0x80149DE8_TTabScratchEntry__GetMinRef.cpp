// 0x80149DE8 TTabScratchEntry::GetMinRef (20b)
struct TTabAdEntry {
    char _pre[6];
    char _min[2];
    char _post[8];
};

struct TTabScratchEntry {
    char _hdr[8];
    TTabAdEntry m_ads[1];
};

char *TTabScratchEntry__GetMinRef(TTabScratchEntry *self, int index) {
    return self->m_ads[index]._min;
}
