// 0x802CE56C (40B) ERedBlackTree::GetSize(void) const
// Walk intrusive linked list from head, count nodes. Next ptr at offset 0x10.

struct ERedBlackTreeNode {
    char _pad_0[0x10];
    ERedBlackTreeNode* next;
};

class ERedBlackTree {
public:
    ERedBlackTreeNode* m_head;
    int GetSize(void) const;
};

int ERedBlackTree::GetSize(void) const {
    ERedBlackTreeNode* n = m_head;
    int count = 0;
    while (n != 0) {
        n = n->next;
        count++;
    }
    return count;
}
