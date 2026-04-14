/* ERoomWall::SetWallUpDownMode(EWallUpDownStateType, bool) at 0x8002CD84 (84B) */

struct EIWallPart {
    void SetWallState(int stateType, int flag);
};

struct WallNode {
    EIWallPart *m_wall;
    char pad[4];
    WallNode *m_next;
};

struct ERoomWall {
    char pad[0x14];
    WallNode *m_head;
    void SetWallUpDownMode(int stateType, int flag);
};

void ERoomWall::SetWallUpDownMode(int stateType, int flag) {
    WallNode *node = m_head;
    while (node != 0) {
        node->m_wall->SetWallState(stateType, flag);
        node = node->m_next;
    }
}
