/* EFloorShdTblNode::~EFloorShdTblNode(void) at 0x80045544 (68B) */

struct ENodeList {
    void RemoveAll(void);
};

void operator delete(void *);

struct EFloorShdTblNode {
    void *m_resource;
    ENodeList m_nodeList;

    ~EFloorShdTblNode(void);
};

EFloorShdTblNode::~EFloorShdTblNode(void) {
    m_nodeList.RemoveAll();
}
