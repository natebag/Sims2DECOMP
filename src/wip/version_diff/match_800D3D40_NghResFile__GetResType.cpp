/* NghResFile::GetResType(Memory::HandleNode *) - 0x800D3D40 (8 bytes) */

namespace Memory { struct HandleNode; }

struct NghResFile {
    int GetResType(Memory::HandleNode *);
};

int NghResFile::GetResType(Memory::HandleNode *) {
    return 0;
}
