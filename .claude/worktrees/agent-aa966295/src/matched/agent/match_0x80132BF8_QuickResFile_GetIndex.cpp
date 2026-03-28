/* QuickResFile::GetIndex(Memory::HandleNode *, short *) - 0x80132BF8 - 12 bytes */
/* li r0, 0; sth r0, 0(r5); blr */

namespace Memory { class HandleNode; }

class QuickResFile {
public:
    void GetIndex(Memory::HandleNode *, short *);
};

void QuickResFile::GetIndex(Memory::HandleNode *, short *result) {
    *result = 0;
}
