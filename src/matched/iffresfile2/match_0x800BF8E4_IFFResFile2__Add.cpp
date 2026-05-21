// 0x800BF8E4 (60B) IFFResFile2::Add(Memory::HandleNode *, int, short, StringBuffer &, bool)
// Direct port of ChainResFile::Add (identical bytes)

namespace Memory { class HandleNode; }
class StringBuffer;

class IFFResFile2 {
public:
    void Add(Memory::HandleNode* node, int id, short version, StringBuffer& strBuf, bool flag);
};

void IFFResFile2::Add(Memory::HandleNode* node, int id, short version, StringBuffer& strBuf, bool flag) {
    char* vt = *(char**)((char*)this + 12);
    short adj = *(short*)(vt + 256);
    void* fn = *(void**)(vt + 260);
    ((void (*)(void*, Memory::HandleNode*, int, short, StringBuffer&, int, bool))fn)
        ((char*)this + adj, node, id, version, strBuf, 0, flag);
}
