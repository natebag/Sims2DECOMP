struct AptPrototype_GSC {
    char pad[0x20];
    void* m_superConstructor;
    void* GetSuperConstructor() const;
};

void* AptPrototype_GSC::GetSuperConstructor() const {
    return m_superConstructor;
}
