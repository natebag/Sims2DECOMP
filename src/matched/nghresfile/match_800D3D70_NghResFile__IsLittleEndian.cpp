/* NghResFile::IsLittleEndian(Memory::HandleNode *) - 0x800D3D70 (8 bytes) */

namespace Memory { struct HandleNode; }

struct NghResFile {
    int IsLittleEndian(Memory::HandleNode *);
};

int NghResFile::IsLittleEndian(Memory::HandleNode *) {
    return 1;
}
