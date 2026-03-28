/* NghResFile::GetID(Memory::HandleNode *, short *) - 0x800D3D48 (16 bytes) */

namespace Memory { struct HandleNode; }

struct NghResFileNode {
    char m_pad[0x08];
    short m_id;
};

struct NghResFile {
    char m_pad[0x180];
    NghResFileNode *m_node;

    void GetID(Memory::HandleNode *, short *outID);
};

void NghResFile::GetID(Memory::HandleNode *, short *outID) {
    *outID = m_node->m_id;
}
