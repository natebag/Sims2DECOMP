// 0x802AA470 (116B) AptNativeHash::GetNextItem(AptHashItem*)
//
// Given the current entry, returns the next "live" entry, or null. The table is
// a flat array of 8-byte {key, value} entries at m_entries (0x04) with
// m_capacity (0x00) slots; the end is computed as a pointer (base + capacity).
// Scanning starts at current + 1 and the bound test is an unsigned pointer
// compare (cmplw). An entry is live when its key is non-null AND not the
// tombstone sentinel (0x8043E6B4); the non-null test is materialised into a 0/1
// boolean before being branched on (li/cmpwi/bne/li). Clean structural C++;
// default scheduling fills the post-load gap with the current+1 computation.

struct AptNativeHashEntry {
    void* m_key;     // 0x00
    void* m_value;   // 0x04
};

struct AptNativeHash {
    int                 m_capacity;  // 0x00 (slot count)
    AptNativeHashEntry* m_entries;   // 0x04
    AptNativeHashEntry* GetNextItem(AptNativeHashEntry* current);
};

// 0x8043E6B4 tombstone/empty-rep sentinel (absolute reloc; name cosmetic).
extern char gAptNativeHashTombstone[];

AptNativeHashEntry* AptNativeHash::GetNextItem(AptNativeHashEntry* current) {
    AptNativeHashEntry* base = m_entries;
    AptNativeHashEntry* e = current;
    if (base == 0)
        return 0;
    AptNativeHashEntry* end = base + m_capacity;
    e = e + 1;
    while (e < end) {
        void* key = e->m_key;
        int occupied = (key != 0);
        if (occupied) {
            if (key != (void*)gAptNativeHashTombstone)
                return e;
        }
        ++e;
    }
    return 0;
}
