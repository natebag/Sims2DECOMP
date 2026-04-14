/* QuickResFile::GetID(Memory::HandleNode *, short *) - 0x80132BEC - 12 bytes */
/* li r0, 0; sth r0, 0(r5); blr */

namespace Memory { class HandleNode; }

class QuickResFile {
public:
    void GetID(Memory::HandleNode *, short *);
};

void QuickResFile::GetID(Memory::HandleNode *, short *result) {
    *result = 0;
}
