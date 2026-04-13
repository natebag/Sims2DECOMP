typedef void* HANDLE;

extern "C" int sub_802D7568(void* buffer, int mode, HANDLE h);

class CTGFileImpl {
    char pad[272];
    HANDLE m_handle;
public:
    int Read(void* buffer, int len);
};

int CTGFileImpl::Read(void* buffer, int len) {
    HANDLE h = this->m_handle;
    int r = 0;
    if (h != 0) {
        r = sub_802D7568(buffer, 1, h);
    }
    return r;
}
