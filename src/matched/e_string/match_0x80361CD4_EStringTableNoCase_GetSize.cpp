// 0x80361CD4 (40B) EStringTableNoCase::GetSize(void) const
// Same shape as EHashTable::GetSize — next ptr at offset 4.

struct EStringTableNoCaseNode {
    int _pad_0;
    EStringTableNoCaseNode* next;
};

class EStringTableNoCase {
public:
    EStringTableNoCaseNode* m_head;
    int GetSize(void) const;
};

int EStringTableNoCase::GetSize(void) const {
    EStringTableNoCaseNode* n = m_head;
    int count = 0;
    while (n != 0) {
        n = n->next;
        count++;
    }
    return count;
}
