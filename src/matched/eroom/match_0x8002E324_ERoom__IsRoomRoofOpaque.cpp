/* 0x8002E324 ERoom::IsRoomRoofOpaque(int, int) (92B) */

struct ERoomData {
    char pad0[24];
    int m_roofOpaque[4];  // +24
};

struct ERBNode {
    char pad[28];
    ERoomData* m_data;  // +28
};

class ERedBlackTree {
public:
    ERBNode* Find(unsigned int key, unsigned int* out) const;
};

class ERoom {
public:
    char pad[160];
    ERedBlackTree m_tree;

    int IsRoomRoofOpaque(int key, int idx);
};

int ERoom::IsRoomRoofOpaque(int key, int idx) {
    ERBNode* node = m_tree.Find(key, 0);
    ERoomData* data;
    if (node == 0 || (data = node->m_data) == 0) {
        return 0;
    }
    return data->m_roofOpaque[idx];
}
