// cXPersonImpl::GetIndAction(int, bool) - 0x80126360 (104B)

class Interaction {
public:
    char m_data[68];
};

struct ActionStorage {
    Interaction actions[10];
    unsigned int startIndex;  // offset 680
    unsigned int endIndex;    // offset 684
};

struct cXPerson_GetIndAction {
    char pad0[0x130];
    ActionStorage m_ring;
    char pad1[0x154];
    int m_pendingFlag;

    Interaction* GetIndAction(int n, bool useQueue);
};

Interaction* cXPerson_GetIndAction::GetIndAction(int n, bool useQueue) {
    if (!useQueue) {
        if (m_pendingFlag != 0)
            n++;
    }
    ActionStorage* stor;
    unsigned int startIdx;
    unsigned int count;
    if (n < 0)
        goto null_return;
    stor = &m_ring;
    startIdx = stor->startIndex;
    count = stor->endIndex - startIdx;
    if ((unsigned int)n < count)
        goto success;
null_return:
    return 0;
success:
    return &stor->actions[(startIdx + n) % 10];
}
