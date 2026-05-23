// 0x800D3D68 (4B) NghResFile::Detach(Memory::HandleNode *)
// Empty stub — single blr.

namespace Memory { class HandleNode; }

class NghResFile {
public:
    void Detach(Memory::HandleNode* node);
};

void NghResFile::Detach(Memory::HandleNode*) {}
