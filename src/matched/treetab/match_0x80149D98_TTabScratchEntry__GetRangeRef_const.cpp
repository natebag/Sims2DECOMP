// 0x80149D98 TTabScratchEntry::GetRangeRef (20b)
struct TTabAdEntry {
    char _pre[8];
    char _range[8];
};

struct TTabScratchEntry {
    char _hdr[8];
    TTabAdEntry m_ads[1];
};

char *TTabScratchEntry__GetRangeRef_const(TTabScratchEntry *self, int index) {
    return self->m_ads[index]._range;
}
