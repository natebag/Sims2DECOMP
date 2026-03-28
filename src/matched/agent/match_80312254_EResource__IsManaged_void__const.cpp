class EResource {
    char pad[4];
    void* m_pManager;
public:
    bool IsManaged() const;
};

bool EResource::IsManaged() const {
    return m_pManager != 0;
}
