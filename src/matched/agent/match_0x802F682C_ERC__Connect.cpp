// 0x802F682C ERC::Connect (16b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;
typedef unsigned char uchar;

struct EDLEntry;

struct ERC {
    uchar m_type;
    char _pad[3];
    EDLEntry *m_target;
};

void ERC__Connect(ERC *self, EDLEntry *src, EDLEntry *dst) {
    self->m_type = 7;
    self->m_target = src;
}
