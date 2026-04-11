typedef void* HANDLE;

// External function at 0x802D7568 - likely DVDRead or similar
extern "C" int sub_802D7568(void* buffer, int mode, HANDLE h);

class CTGFileImpl {
    char pad[272];
    HANDLE m_handle;  // offset 272
public:
    int Read(void* buffer, int len);
};

int CTGFileImpl::Read(void* buffer, int len) {
    HANDLE h = this->m_handle;
    if (h == 0) {
        return 0;
    }
    return sub_802D7568(buffer, 1, h);
}
