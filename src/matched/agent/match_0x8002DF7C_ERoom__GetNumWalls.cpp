/* ERoom::GetNumWalls(unsigned short) at 0x8002DF7C (112B) */

struct ERoomWall {
    int CountWalls(void);
};

struct WallNode {
    ERoomWall *m_wall;
    char pad[4];
    WallNode *m_next;
};

struct RoomData {
    char pad[0x1C];
    void *m_ptr;
};

struct NodeList {
    WallNode *m_head;
};

struct ERedBlackTree {
    RoomData *Find(unsigned int key, unsigned int *out);
};

struct ERoom {
    char pad[0x94];
    ERedBlackTree m_tree;
    int GetNumWalls(unsigned short wallId);
};

int ERoom::GetNumWalls(unsigned short wallId) {
    RoomData *data = m_tree.Find(wallId, 0);
    int count = 0;
    if (data != 0) {
        NodeList *list = (NodeList *)data->m_ptr;
        if (list != 0) {
            WallNode *node = list->m_head;
            while (node != 0) {
                count = count + node->m_wall->CountWalls();
                node = node->m_next;
            }
        }
    }
    return count;
}
