// EREdithTreeSet::GetTreeIDByIndex(int) - 0x8030F9D0 (44B)
// 1-based index into entries array (stride 12). Returns 0 for idx<=0 or idx>count.

struct EREdithTreeEntry {
    int treeID;
    char _pad[8];
};

class EREdithTreeSet {
public:
    char _pad[0x18];
    int m_count;                  // +0x18
    EREdithTreeEntry* m_entries;  // +0x1c
    int GetTreeIDByIndex(int idx);
};

int EREdithTreeSet::GetTreeIDByIndex(int idx)
{
    idx -= 1;
    if (idx < 0) goto zero;
    if (idx < m_count) goto load;
zero:
    return 0;
load:
    return m_entries[idx].treeID;
}
