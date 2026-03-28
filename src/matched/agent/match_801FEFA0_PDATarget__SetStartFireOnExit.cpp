class PDATarget {
public:
    char pad[0x16C];
    int m_startFireOnExit;
    int SetStartFireOnExit(int val);
};

int PDATarget::SetStartFireOnExit(int val) {
    int old = m_startFireOnExit;
    m_startFireOnExit = val;
    return old;
}
