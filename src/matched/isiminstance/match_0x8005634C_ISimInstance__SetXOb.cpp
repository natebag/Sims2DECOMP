// 0x8005634C ISimInstance::SetXOb (8B)

struct ISimInstance_SetXOb {
    char pad[0x328];
    void* m_val;
    void SetXOb(void* v);
};

void ISimInstance_SetXOb::SetXOb(void* v) { m_val = v; }
