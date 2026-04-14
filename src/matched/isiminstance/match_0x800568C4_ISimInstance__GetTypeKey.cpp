// 0x800568C4 ISimInstance::GetTypeKey (12B) const

extern int g_ISimInstance_TypeKey[3];

struct ISimInstance_GetTypeKey {
    int GetTypeKey() const;
};

int ISimInstance_GetTypeKey::GetTypeKey() const {
    return g_ISimInstance_TypeKey[0];
}
