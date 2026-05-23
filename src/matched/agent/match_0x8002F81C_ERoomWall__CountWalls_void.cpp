// 0x8002F81C ERoomWall::CountWalls(void) (48 B)
// FLAGS: -fno-schedule-insns
struct WallNode { void* m_wall; char _pad[4]; WallNode* m_next; };
struct ERoomWall { char _pad[0x14]; WallNode* m_nodes; int CountWalls(); };
int ERoomWall::CountWalls() {
    WallNode* n = m_nodes;
    int count = 0;
    if (!n) return 0;
    do {
        if (n->m_wall) count++;
        n = n->m_next;
    } while (n);
    return count;
}
