/* TreeStack::Reset - 0x801490C4 (12 bytes) */

class TreeStack {
public:
    char pad[0x08];
    int m_begin;
    int m_current;
    void Reset();
};

void TreeStack::Reset() {
    m_current = m_begin;
}
