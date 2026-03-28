class IHRecord {
public:
    int _pad0;
    IHRecord* m_next;
    int m_interaction;
    IHRecord* m_alternate;
};

class InteractionHelper {
public:
    int GetCount(IHRecord* record);
};

int InteractionHelper::GetCount(IHRecord* record) {
    int count = 0;
    if (record == 0) {
        return count;
    }
    do {
        count++;
        if (record->m_interaction == 0) {
            record = record->m_next;
        } else {
            record = record->m_alternate;
        }
    } while (record != 0);
    return count;
}
