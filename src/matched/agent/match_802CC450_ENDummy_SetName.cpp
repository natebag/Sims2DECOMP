void strncpy_stub(void* dst, void* src, int len);

struct ENDummy_SN {
    void SetName(char* name);
};

void ENDummy_SN::SetName(char* name) {
    strncpy_stub(this, name, 64);
}
