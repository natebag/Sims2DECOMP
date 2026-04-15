/* 0x8002E2C4 ERoom::GetOccludeAlpha(int, int) (96B) */

struct ERoomData {
    char pad0[8];
    float m_alpha[4];  // +8
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

    float GetOccludeAlpha(int key, int idx);
};

extern char g_ERoomDefaultAlpha[100];

float ERoom::GetOccludeAlpha(int key, int idx) {
    ERBNode* node = m_tree.Find(key, 0);
    ERoomData* data;
    if (node == 0 || (data = node->m_data) == 0) {
        return *(float*)g_ERoomDefaultAlpha;
    }
    return data->m_alpha[idx];
}
