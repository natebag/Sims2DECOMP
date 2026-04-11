typedef void* HANDLE;

// External function at 0x802D75E0 - likely DVDSeek or similar
extern "C" int sub_802D75E0(HANDLE, int, int);

class CTGFileImpl {
    char pad[272];
    HANDLE m_handle;  // offset 272
public:
    int SeekPastEnd(int offset);
};

int CTGFileImpl::SeekPastEnd(int offset) {
    sub_802D75E0(this->m_handle, offset, 0);
    return 0;
}
