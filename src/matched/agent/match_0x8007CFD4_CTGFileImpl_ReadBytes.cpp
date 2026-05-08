// 0x8007CFD4 CTGFileImpl::ReadBytes(unsigned char*, int) (68B)
struct CTGFileImpl;

struct VTable {
    char pad[16];
    short m_adj;
    short m_pad;
    int (*m_read)(void*, unsigned char*, int);
};

struct CTGFileBase {
    VTable* m_vt;
};

int CTGFileImpl__ReadBytes(CTGFileBase* self, unsigned char* buf, int len) {
    VTable* vt = self->m_vt;
    int got = vt->m_read((char*)self + vt->m_adj, buf, len);
    return got != 0 ? 1 : 0;
}
