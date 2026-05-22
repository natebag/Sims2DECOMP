// 0x800eca9c ObjectFolderImpl::CountSelectors(void) const (72B)
// Variant: outer do-while loop, hoping for r11 as idx

struct SelectorNode {
    char _pad[164];
    SelectorNode* m_next;  // +164
};

struct ObjectFolderImpl {
    char _pad[64];
    SelectorNode* m_selectors[256];  // +64
    int CountSelectors() const;
};

int ObjectFolderImpl::CountSelectors() const {
    int total = 0;
    int i = 0;
    do {
        SelectorNode* node = m_selectors[i];
        int count = 0;
        if (node) {
            do {
                node = node->m_next;
                count++;
            } while (node);
        }
        total += count;
        i++;
    } while (i <= 255);
    return total;
}
