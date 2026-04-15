// 0x800D3D40 NghResFile::GetResType (8B) — stub returns 0
namespace Memory { struct HandleNode; }
struct NghResFile {
    int GetResType(Memory::HandleNode* n);
};

int NghResFile::GetResType(Memory::HandleNode*) { return 0; }
