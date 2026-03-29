struct EResource {
    void DelRef();
};

struct ENodeList {
    void RemoveAll();
};

struct EFloorShdTblNode {
    EResource *m_resource;
    ENodeList m_nodeList;

    void CleanUp();
};

void EFloorShdTblNode::CleanUp() {
    m_nodeList.RemoveAll();
    if (m_resource != 0) {
        m_resource->DelRef();
    }
    m_resource = 0;
}
