class ENgcMemoryCard {
    char pad[4];
    void* m_pOperation;
public:
    bool IsCardOperationInProgress() const;
};

bool ENgcMemoryCard::IsCardOperationInProgress() const {
    return m_pOperation != 0;
}
