/* ERoomWall::CountWalls(void) - 0x8002F81C (48B) */

struct ERoomWallNode {
    void* m_field_0;
    char pad[4];
    ERoomWallNode* m_next;  // +8
};

class ERoomWall {
public:
    char pad[20];
    ERoomWallNode* m_head;

    int CountWalls(void);
};

int ERoomWall::CountWalls(void) {
    int count = 0;
    ERoomWallNode* p = m_head;
    while (p != 0) {
        if (p->m_field_0 != 0) count++;
        p = p->m_next;
    }
    return count;
}
