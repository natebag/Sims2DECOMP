/* EFloorShdTblNode::CleanUp(void) at 0x80045588 (72B) */

struct ENodeList {
    void RemoveAll(void);
};

struct EResource {
    void DelRef(void);
};

struct EFloorShdTblNode {
    EResource *m_resource;
    ENodeList m_nodeList;

    void CleanUp(void);
};

void EFloorShdTblNode::CleanUp(void) {
    m_nodeList.RemoveAll();
    if (m_resource != 0) {
        m_resource->DelRef();
        m_resource = 0;
    }
}
