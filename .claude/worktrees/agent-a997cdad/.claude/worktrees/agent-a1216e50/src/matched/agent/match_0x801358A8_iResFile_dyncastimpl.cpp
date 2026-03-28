/* iResFile::_dyncastimpl(SCID) - 0x801358A8 - 16 bytes */
/* cmpwi r4, 0x10; beqlr; li r3, 0; blr */

typedef int SCID;

class iResFile {
public:
    iResFile* _dyncastimpl(SCID id);
};

iResFile* iResFile::_dyncastimpl(SCID id) {
    if (id == 0x10) return this;
    return 0;
}
