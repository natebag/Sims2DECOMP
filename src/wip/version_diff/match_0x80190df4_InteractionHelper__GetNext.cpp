// 0x80190df4 InteractionHelper::GetNext(IHRecord *) (24B)

struct IHRecord {
    char pad[0x04];
    int m_field4;
    char pad2[0x04];
    int m_fieldC;
};

struct InteractionHelper {
    int GetNext(IHRecord* rec);
};

int InteractionHelper::GetNext(IHRecord* rec) {
    int tmp = rec->m_field4;
    int result = tmp;
    if (tmp != 0) return result;
    return rec->m_fieldC;
}
