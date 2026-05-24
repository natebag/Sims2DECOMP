// 0x803613AC (40B) EStringRedBlackTreeNoCase::GetSize(void) const
// Same shape as ERedBlackTree::GetSize — next ptr at offset 0x10.

struct EStringRedBlackTreeNoCaseNode {
    char _pad_0[0x10];
    EStringRedBlackTreeNoCaseNode* next;
};

class EStringRedBlackTreeNoCase {
public:
    EStringRedBlackTreeNoCaseNode* m_head;
    int GetSize(void) const;
};

int EStringRedBlackTreeNoCase::GetSize(void) const {
    EStringRedBlackTreeNoCaseNode* n = m_head;
    int count = 0;
    while (n != 0) {
        n = n->next;
        count++;
    }
    return count;
}
