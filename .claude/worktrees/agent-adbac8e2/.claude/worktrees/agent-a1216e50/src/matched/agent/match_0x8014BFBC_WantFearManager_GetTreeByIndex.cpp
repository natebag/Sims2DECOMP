/* WantFearManager::GetTreeByIndex(int) const - 0x8014BFBC - 16 bytes */
/* lwz r9, 0xC(r3); rlwinm r4, r4, 2, 0, 29; lwzx r3, r4, r9; blr */

class WantFearManager {
public:
    char _pad[0xC];
    int* m_trees;

    int GetTreeByIndex(int index) const;
};

int WantFearManager::GetTreeByIndex(int index) const {
    return m_trees[index];
}
