// 0x800D8D10 (128B) NghResFile::FindNodeInRegistry(NghResFile::RegistryID, NghResFile::RegistryNode&)
// Linear search with 2x unrolled loop, copies 16B entry on match.

struct NghResFile {
    struct RegistryNode {
        int m_id;
        int m_field1;
        int m_field2;
        int m_field3;
    };
    typedef int RegistryID;
    
    char pad[0x10];
    RegistryNode* m_nodes;
    RegistryNode* m_end;
    
    int FindNodeInRegistry(RegistryID id, RegistryNode& out);
};

int NghResFile::FindNodeInRegistry(RegistryID id, RegistryNode& out) {
    RegistryNode* node = m_nodes;
    RegistryNode* end = m_end;
    
    if (node >= end) {
        return 0;
    }
    
    if (node->m_id == id) {
        out = *node;
        return 1;
    }
    
    node++;
    while (node < end) {
        if (node->m_id == id) {
            out = *node;
            return 1;
        }
        node++;
    }
    
    return 0;
}
