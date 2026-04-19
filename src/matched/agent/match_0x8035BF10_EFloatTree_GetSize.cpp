// 0x8035BF10 (40B) EFloatTree::GetSize(void) const
// Same shape as ERedBlackTree::GetSize — next ptr at offset 0x10.

struct EFloatTreeNode {
    char _pad_0[0x10];
    EFloatTreeNode* next;
};

class EFloatTree {
public:
    EFloatTreeNode* m_head;
    int GetSize(void) const;
};

int EFloatTree::GetSize(void) const {
    EFloatTreeNode* n = m_head;
    int count = 0;
    while (n != 0) {
        n = n->next;
        count++;
    }
    return count;
}
