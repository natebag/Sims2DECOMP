// FLAGS: -fno-schedule-insns
// CTGFileImpl::GetSize(void) at 0x8007CE84 (100B)

struct EftellVt { char pad[0x30]; short m_off; int (*m_fn)(void *); };
struct EftellObj {
    char pad[0x28];
    EftellVt *m_vt;
    int eftell(void);
    int efseek(int offset, int whence);
};

struct CTGFileImpl {
    char pad[0x110];
    EftellObj *m_file;
    int GetSize(void);
};

int CTGFileImpl::GetSize(void) {
    int curpos = (*(EftellObj *volatile *)&m_file)->eftell();
    (*(EftellObj *volatile *)&m_file)->efseek(0, 2);
    int size = (*(EftellObj *volatile *)&m_file)->eftell();
    (*(EftellObj *volatile *)&m_file)->efseek(curpos, 0);
    return size;
}
