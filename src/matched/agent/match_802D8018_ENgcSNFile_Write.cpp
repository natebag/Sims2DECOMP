struct SysFile_W {
    int Write(void* buf, unsigned int count);
};
struct ENSF_W {
    char pad[0x2C];
    SysFile_W* m_sys;
    int Write(void* buf, unsigned int count);
};
int ENSF_W::Write(void* buf, unsigned int count) {
    return m_sys->Write(buf, count);
}
