// 0x800BF8E4 (60B) IFFResFile2::Add(Memory::HandleNode*, int, short, StringBuffer&, bool)

namespace Memory { class HandleNode; }
class StringBuffer;

class IFFResFile2 {
public:
    void Add(Memory::HandleNode* hn, int idx, short sh, StringBuffer& sb, bool flag);
};

void IFFResFile2::Add(Memory::HandleNode* hn, int idx, short sh, StringBuffer& sb, bool flag) {
    char* obj = (char*)this;
    char* vt = *(char**)(obj + 12);
    short adj = *(short*)(vt + 256);
    void* fn = *(void**)(vt + 260);
    typedef void (*Fn)(void*, Memory::HandleNode*, int, short, StringBuffer&, int, bool);
    ((Fn)fn)(obj + adj, hn, idx, sh, sb, 0, flag);
}
