struct FileCreator_GCB {
    void* m_creatorCB;
    void* GetCreatorCB() const;
};

void* FileCreator_GCB::GetCreatorCB() const {
    return m_creatorCB;
}
