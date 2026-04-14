// 0x8007D018 CTGFileImpl::WriteBytes(unsigned char*, int) (76B)
struct CTGFileImpl;

struct VTable {
    char pad[24];
    short m_adj;
    short m_pad;
    int (*m_write)(void*, unsigned char*, int);
};

struct CTGFileBase {
    VTable* m_vt;
};

int CTGFileImpl__WriteBytes(CTGFileBase* self, unsigned char* buf, int len) {
    VTable* vt = self->m_vt;
    int written = vt->m_write((char*)self + vt->m_adj, buf, len);
    return written == len;
}
