// 0x80045520 EFloorShdTblNode::EFloorShdTblNode(void) (36B)

struct EFloorShdTblNode {
    int m_0;
    int m_4;
    int m_8;
    int m_12;
    EFloorShdTblNode();
};

EFloorShdTblNode::EFloorShdTblNode() {
    EFloorShdTblNode* p = this;
    int* q = &p->m_4;
    *(volatile int*)&q[1] = 0;
    *(volatile int*)&q[0] = 0;
    *(volatile int*)&q[2] = 1;
    *(volatile int*)&p->m_0 = 0;
}
