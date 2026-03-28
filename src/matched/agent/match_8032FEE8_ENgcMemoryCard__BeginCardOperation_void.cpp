class ENgcMemoryCard { char pad[4]; int m_opCount; public: void BeginCardOperation(); };
void ENgcMemoryCard::BeginCardOperation() { m_opCount++; }
