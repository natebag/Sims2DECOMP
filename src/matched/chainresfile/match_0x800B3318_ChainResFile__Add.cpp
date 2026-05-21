// 0x800B3318 (60B) ChainResFile::Add(Memory::HandleNode *, int, short, StringBuffer &, bool)

namespace Memory { class HandleNode; }
class StringBuffer;

class ChainResFile {
public:
    void Add(Memory::HandleNode* node, int id, short version, StringBuffer& strBuf, bool flag);
};

void ChainResFile::Add(Memory::HandleNode* node, int id, short version, StringBuffer& strBuf, bool flag) {
    char* vt = *(char**)((char*)this + 12);
    short adj = *(short*)(vt + 256);
    void* fn = *(void**)(vt + 260);
    ((void (*)(void*, Memory::HandleNode*, int, short, StringBuffer&, int, bool))fn)
        ((char*)this + adj, node, id, version, strBuf, 0, flag);
}
