// 0x80149C44 TTabScratchEntry::SetAvailableToAdults (32b)
// FLAGS: -fno-schedule-insns
typedef unsigned short ushort;

struct TTabScratchEntry {
    char _pad[0x110];
    ushort m_flags;
};

void TTabScratchEntry__SetAvailableToAdults(TTabScratchEntry *self, int val) {
    unsigned int f = self->m_flags;
    f = f & ~64u;
    self->m_flags = (ushort)f;
    if (!val) {
        f = f | 64u;
        self->m_flags = (ushort)f;
    }
}
