// 0x80132C4C (4B) QuickResFile::Add — stub (no-op)

namespace Memory { class HandleNode; }
class StringBuffer;

class QuickResFile {
public:
    void Add(Memory::HandleNode*, int, short, StringBuffer&, bool);
};

void QuickResFile::Add(Memory::HandleNode*, int, short, StringBuffer&, bool) {
}
