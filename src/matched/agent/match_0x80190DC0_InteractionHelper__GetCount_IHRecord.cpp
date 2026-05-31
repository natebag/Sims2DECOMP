// 0x80190DC0 InteractionHelper::GetCount(IHRecord*) (52 B)

struct IHRecord {
    char pad_0000[0x4];
    IHRecord* m_field4;
    int m_field8;
    IHRecord* m_fieldC;
};

struct InteractionHelper {
    int GetCount(IHRecord* node);
};

int InteractionHelper::GetCount(IHRecord* node) {
    int count = 0;
    if (node == 0) {
        return 0;
    }
    do {
        count++;
        if (node->m_field8 == 0) {
            node = node->m_field4;
        } else {
            node = node->m_fieldC;
        }
    } while (node != 0);
    return count;
}
