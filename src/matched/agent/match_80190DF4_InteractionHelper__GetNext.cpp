class IHRecord {
public:
    int _pad0;
    IHRecord* m_next;
    int _pad1;
    IHRecord* m_alternate;
};

class InteractionHelper {
public:
    IHRecord* GetNext(IHRecord* record);
};

IHRecord* InteractionHelper::GetNext(IHRecord* record) {
    IHRecord* result = record->m_next;
    if (result != 0) {
        result = record->m_alternate;
    }
    return result;
}
