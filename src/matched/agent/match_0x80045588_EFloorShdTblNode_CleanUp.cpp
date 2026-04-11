// 0x80045588 EFloorShdTblNode::CleanUp (72b)

struct ENodeList {};  // Embedded at offset 4

struct EFloorShdTblNode {
    void* m_resource;      // offset 0
    ENodeList m_list;      // offset 4 (embedded, not pointer)
    
    void CleanUp();
};

extern "C" void ENodeList_RemoveAll(ENodeList* list);
extern "C" void EResource_DelRef(void* res);

void EFloorShdTblNode::CleanUp() {
    ENodeList_RemoveAll(&m_list);
    if (m_resource) {
        EResource_DelRef(m_resource);
        m_resource = 0;
    }
}
