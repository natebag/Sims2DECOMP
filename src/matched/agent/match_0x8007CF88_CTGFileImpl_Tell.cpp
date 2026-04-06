typedef void* HANDLE;

// External function at 0x802D7648 - likely DVDGetLength or similar
extern "C" int sub_802D7648(HANDLE);

class CTGFileImpl {
    char pad[272];
    HANDLE m_handle;  // offset 272
public:
    int Tell();
};

int CTGFileImpl::Tell() {
    HANDLE h = this->m_handle;
    if (h == 0) {
        return 0;
    }
    return sub_802D7648(h);
}
