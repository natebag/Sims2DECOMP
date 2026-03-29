typedef int SCID;

class QuickResFile {
public:
    QuickResFile* _dyncastimpl(SCID id);
};

QuickResFile* QuickResFile::_dyncastimpl(SCID id) {
    if (id == 0x11) return this;
    QuickResFile* result = 0;
    if (id == 0x10)
        result = this;
    return result;
}
