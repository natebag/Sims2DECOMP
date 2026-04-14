// 0x80056354 ISimInstance::GetXOb (8B)

struct ISimInstance_GetXOb {
    char pad[0x328];
    void* m_val;
    void* GetXOb();
};

void* ISimInstance_GetXOb::GetXOb() { return m_val; }
