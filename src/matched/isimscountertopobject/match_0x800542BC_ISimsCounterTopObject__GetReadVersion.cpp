// 0x800542BC ISimsCounterTopObject::GetReadVersion (12B)

struct RVBlock_ISimsCounterTopObject { unsigned short ver[256]; };
extern RVBlock_ISimsCounterTopObject g_ISimsCounterTopObject_ReadVersion[3];

struct ISimsCounterTopObject_GRV {
    unsigned short GetReadVersion();
};

unsigned short ISimsCounterTopObject_GRV::GetReadVersion() {
    return g_ISimsCounterTopObject_ReadVersion[0].ver[0];
}
