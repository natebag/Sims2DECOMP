// 0x8015E688 TreeTableEntryQuickData::GetDebugOnly(void) const (60B)
// `if (!(flags & 128))` gives bne-forward for flags set; shared li r3,1/blr block
// `if (val == 33) result = 1; return result` gives bnelr naturally

struct TreeTableNodeLink {
    int* m_inner;
};

struct TreeTableNode {
    char pad[16];
    int m_flags;
    char pad2[8];
    TreeTableNodeLink* m_link;
};

struct TreeTableEntryQuickData {
    int m_pad;
    TreeTableNode* m_node;

    int GetDebugOnly() const;
};

int TreeTableEntryQuickData::GetDebugOnly() const {
    TreeTableNode* node = m_node;
    int result = 0;
    if (!(node->m_flags & 128)) {
        TreeTableNodeLink* link = node->m_link;
        int* inner_raw = 0;
        if (link)
            inner_raw = link->m_inner;
        if (*(unsigned short*)inner_raw == 33) result = 1;
        return result;
    }
    return 1;
}
