/* SetAllUpOrDownForList(bool, TNodeList<ERoomWall *> &) at 0x8002E84C (88B) */

struct ERoomWall {
    void SetWallUpDownMode(int stateType, int flag);
};

struct WallNode {
    ERoomWall *m_wall;
    char pad[4];
    WallNode *m_next;
};

struct NodeList {
    WallNode *m_head;
};

void SetAllUpOrDownForList(int up, NodeList *list) {
    WallNode *node = list->m_head;
    if (node != 0) {
        int state = up ? 0 : 2;
        do {
            node->m_wall->SetWallUpDownMode(state, 1);
            node = node->m_next;
        } while (node != 0);
    }
}
