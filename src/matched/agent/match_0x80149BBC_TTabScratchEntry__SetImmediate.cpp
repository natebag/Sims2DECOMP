// 0x80149BBC TTabScratchEntry::SetImmediate (32b)
// FLAGS: -fno-schedule-insns
typedef unsigned short ushort;

struct TTabScratchEntry {
    char _pad[0x110];
    ushort m_flags;
};

void TTabScratchEntry__SetImmediate(TTabScratchEntry *self, int val) {
    unsigned int f = self->m_flags;
    f = f & ~4u;
    self->m_flags = (ushort)f;
    if (val) {
        f = f | 4u;
        self->m_flags = (ushort)f;
    }
}
