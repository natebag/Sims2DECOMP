// cXPersonImpl::DeleteTopAction(void) - 0x8012AD28 (112B)

class Interaction {
public:
    char m_data[68];
};

struct ActionStorage {
    Interaction actions[10];
    unsigned int startIndex;
    unsigned int endIndex;
};

struct cXPerson_DeleteTopAction {
    char pad0[0x130];
    ActionStorage m_ring;
    char pad1[0x154];
    int m_pendingFlag;

    void ActionSkipped(Interaction& action);
    void DeleteTopAction();
};

void cXPerson_DeleteTopAction::DeleteTopAction() {
    int pending = 0;
    if (m_pendingFlag != 0) pending = 1;
    ActionStorage* stor = &m_ring;
    unsigned int startIdx = stor->startIndex;
    unsigned int count = stor->endIndex - startIdx;
    if (count <= (unsigned int)pending) return;
    ActionSkipped(stor->actions[(startIdx + pending) % 10]);
}
