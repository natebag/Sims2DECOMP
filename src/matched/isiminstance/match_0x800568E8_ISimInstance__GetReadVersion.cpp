// 0x800568E8 ISimInstance::GetReadVersion (12B)

struct RVBlock_ISimInstance { unsigned short ver[256]; };
extern RVBlock_ISimInstance g_ISimInstance_ReadVersion[3];

struct ISimInstance_GetReadVersion {
    unsigned short GetReadVersion();
};

unsigned short ISimInstance_GetReadVersion::GetReadVersion() {
    return g_ISimInstance_ReadVersion[0].ver[0];
}
