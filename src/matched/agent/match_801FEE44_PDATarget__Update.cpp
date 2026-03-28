class SomeSubObj {
public:
    void DoUpdate(void);
};

class PDATarget {
public:
    char pad[0x84];
    SomeSubObj m_subObj;
    char pad2[0xE0];
    int m_pendingUpdate;
    void Update(void);
};

void PDATarget::Update(void) {
    if (m_pendingUpdate != 0) {
        m_pendingUpdate = 0;
        m_subObj.DoUpdate();
    }
}
