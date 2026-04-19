// 0x802C8F0C (40B) EHashTable::GetSize(void) const
// Walk intrusive linked list from head, count nodes. Next ptr at offset 4.

struct EHashTableNode {
    int _pad_0;
    EHashTableNode* next;
};

class EHashTable {
public:
    EHashTableNode* m_head;
    int GetSize(void) const;
};

int EHashTable::GetSize(void) const {
    EHashTableNode* n = m_head;
    int count = 0;
    while (n != 0) {
        n = n->next;
        count++;
    }
    return count;
}
