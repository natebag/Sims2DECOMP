// 0x80054450 IShrubObject::GetReadVersion (12B)

struct RVBlock_IShrubObject { unsigned short ver[256]; };
extern RVBlock_IShrubObject g_IShrubObject_ReadVersion[3];

struct IShrubObject_GRV {
    unsigned short GetReadVersion();
};

unsigned short IShrubObject_GRV::GetReadVersion() {
    return g_IShrubObject_ReadVersion[0].ver[0];
}
