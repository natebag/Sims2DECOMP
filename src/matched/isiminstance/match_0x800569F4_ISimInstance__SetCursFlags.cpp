// 0x800569F4 ISimInstance::SetCursFlags (8B)

struct ISimInstance_SetCursFlags {
    char pad[0x32C];
    unsigned int m_val;
    void SetCursFlags(unsigned int v);
};

void ISimInstance_SetCursFlags::SetCursFlags(unsigned int v) { m_val = v; }
