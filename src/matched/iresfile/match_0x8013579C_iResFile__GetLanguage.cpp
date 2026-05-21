// 0x8013579C (60B) iResFile::GetLanguage(Memory::HandleNode *)

namespace Memory { class HandleNode; }

class iResFile {
public:
    int GetLanguage(Memory::HandleNode* node);
};

int iResFile::GetLanguage(Memory::HandleNode* node) {
    int stack_data;
    char* vt = *(char**)((char*)this + 12);
    short adj = *(short*)(vt + 176);
    void* fn = *(void**)(vt + 180);
    ((void (*)(void*, Memory::HandleNode*, int*))fn)((char*)this + adj, node, &stack_data);
    return 0;
}
