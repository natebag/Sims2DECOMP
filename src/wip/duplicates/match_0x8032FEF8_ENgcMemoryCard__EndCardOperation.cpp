struct ENgcMemoryCard {
    char _p[0x04];
    int m_opCount;
    void EndCardOperation();
};
void ENgcMemoryCard::EndCardOperation() { m_opCount--; }
