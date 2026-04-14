// 0x8007CEF0 CTGFileImpl::Read(void*, int) (48B)
typedef void* HANDLE;

extern "C" int sub_802D7568(void* buf, int one, int len, HANDLE handle);

struct CTGFileImpl {
    char pad[272];
    HANDLE m_handle;
};

int CTGFileImpl__Read(CTGFileImpl* self, void* buf, int len) {
    HANDLE h = self->m_handle;
    if (h == 0) return 0;
    return sub_802D7568(buf, 1, len, h);
}
