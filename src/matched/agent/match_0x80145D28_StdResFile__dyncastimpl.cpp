typedef int SCID;

class StdResFile {
public:
    StdResFile* _dyncastimpl(SCID id);
};

StdResFile* StdResFile::_dyncastimpl(SCID id) {
    if (id == 0x0D) return this;
    if (id == 0x0E) return this;
    if (id == 0x0F) return this;
    StdResFile* result = 0;
    if (id == 0x10)
        result = this;
    return result;
}
