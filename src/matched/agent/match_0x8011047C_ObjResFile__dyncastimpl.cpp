typedef int SCID;

class ObjResFile {
public:
    ObjResFile* _dyncastimpl(SCID id);
};

ObjResFile* ObjResFile::_dyncastimpl(SCID id) {
    if (id == 0x0C) return this;
    if (id == 0x0D) return this;
    if (id == 0x0E) return this;
    if (id == 0x0F) return this;
    ObjResFile* result = 0;
    if (id == 0x10)
        result = this;
    return result;
}
