class ENgcMemoryCard { char pad[4]; int m_opCount; public: void EndCardOperation(); };
void ENgcMemoryCard::EndCardOperation() { m_opCount--; }
