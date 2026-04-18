// 0x80299930 (64B) AptDisplayListState::remove(AptCIH *)

struct AptDLS_Node {
    char pad[0x50];
    AptDLS_Node* m_50;
    AptDLS_Node* m_54;

    AptDLS_Node* remove();
};

AptDLS_Node* AptDLS_Node::remove() {
    AptDLS_Node* r11 = m_50;
    if (r11) {
        r11->m_54 = m_54;
    }
    r11 = m_54;
    if (r11) {
        r11->m_50 = m_50;
    }
    m_50 = 0;
    m_54 = 0;
    return this;
}
