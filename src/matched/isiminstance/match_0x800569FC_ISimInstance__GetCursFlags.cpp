// 0x800569FC ISimInstance::GetCursFlags (8B)

struct ISimInstance_GetCursFlags {
    char pad[0x32C];
    unsigned int m_val;
    unsigned int GetCursFlags();
};

unsigned int ISimInstance_GetCursFlags::GetCursFlags() { return m_val; }
