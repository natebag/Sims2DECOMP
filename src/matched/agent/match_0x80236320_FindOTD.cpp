struct EOrderTableData {
    char pad0[0x0C];
    int m_sortKey;
    char pad1[0x08];
    int m_roomId;
    int m_floorId;
    char pad2[0x04];
    int m_flags;
    EOrderTableData *m_next;
};

EOrderTableData *FindOTD(EOrderTableData *head, EOrderTableData &target) {
    EOrderTableData *node = head;
    while (node != 0) {
        if (target.m_roomId == node->m_roomId &&
            target.m_floorId == node->m_floorId &&
            target.m_flags == node->m_flags &&
            target.m_sortKey == node->m_sortKey)
            return node;
        node = node->m_next;
    }
    return 0;
}
