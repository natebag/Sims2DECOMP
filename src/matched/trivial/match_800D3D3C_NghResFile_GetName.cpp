// 0x800D3D3C (4 bytes)
// NghResFile::GetName(Memory::HandleNode *, StringBuffer &)
class Memory__HandleNode;
class StringBuffer;
class NghResFile {
public:
    void GetName(Memory__HandleNode* node, StringBuffer& buf);
};

void NghResFile::GetName(Memory__HandleNode* node, StringBuffer& buf) {
}
