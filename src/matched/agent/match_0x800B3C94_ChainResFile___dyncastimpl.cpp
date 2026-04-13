// 0x800B3C94 ChainResFile::_dyncastimpl(SCID) (32B)
struct ChainResFile {
    void* _dyncastimpl(int scid);
};
void* ChainResFile::_dyncastimpl(int scid) {
    if (scid == 15) return this;
    int r = 0;
    if (scid == 16) r = (int)this;
    return (void*)r;
}
