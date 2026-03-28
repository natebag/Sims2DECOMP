struct ENgcMemoryCard {
    char _p[0x04];
    int m_opCount;
    void BeginCardOperation();
};
void ENgcMemoryCard::BeginCardOperation() { m_opCount++; }
