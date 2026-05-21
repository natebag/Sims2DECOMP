// 0x802b5b44 DOGMA_PoolManager::GetTotalBytesUsed(void) (40B)
// Traverses linked list computing total (end - start) per node. Do-while terminates when next==0.

struct DPoolNode {
    DPoolNode* next;
    char* end;
    char* start;
};

struct DOGMA_PoolManager {
    int m_unused;
    DPoolNode* m_first;
    int GetTotalBytesUsed();
};

int DOGMA_PoolManager::GetTotalBytesUsed() {
    DPoolNode* node = m_first;
    int total = 0;
    do {
        total += node->end - node->start;
        node = node->next;
    } while (node);
    return total;
}
