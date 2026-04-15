/* SeqResFile::_dyncastimpl(SCID) - 0x8013E420 (40B) */

class SeqResFile {
public:
    void* _dyncastimpl(int id);
};

void* SeqResFile::_dyncastimpl(int id) {
    if (id == 14) return this;
    if (id == 15) return this;
    void* r = 0;
    if (id == 16) r = this;
    return r;
}
