// 0x800568D0 ISimInstance::GetTypeVersion (12B) const

struct VerBlock_ISimInstance { unsigned short ver[256]; };
extern VerBlock_ISimInstance g_ISimInstance_TypeVersion[3];

struct ISimInstance_GetTypeVersion {
    unsigned short GetTypeVersion() const;
};

unsigned short ISimInstance_GetTypeVersion::GetTypeVersion() const {
    return g_ISimInstance_TypeVersion[0].ver[0];
}
