// 0x80149CAC TTabScratchEntry::SetDebugOnly (32b)
// FLAGS: -fno-schedule-insns
typedef unsigned short ushort;

struct TTabScratchEntry {
    char _pad[0x110];
    ushort m_flags;
};

void TTabScratchEntry__SetDebugOnly(TTabScratchEntry *self, int val) {
    unsigned int f = self->m_flags;
    f = f & ~128u;
    self->m_flags = (ushort)f;
    if (val) {
        f = f | 128u;
        self->m_flags = (ushort)f;
    }
}
