class CASTarget {
public:
    char _pad[0x1354];
    void *m_npcEditor;

    void *GetNPCEditor();
};

void *CASTarget::GetNPCEditor() {
    return m_npcEditor;
}
