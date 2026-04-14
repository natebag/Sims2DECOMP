// 0x800542A4 ISimsCounterTopObject::GetTypeVersion (12B) const

struct VerBlock_ISimsCounterTopObject { unsigned short ver[256]; };
extern VerBlock_ISimsCounterTopObject g_ISimsCounterTopObject_TypeVersion[3];

struct ISimsCounterTopObject_GTV {
    unsigned short GetTypeVersion() const;
};

unsigned short ISimsCounterTopObject_GTV::GetTypeVersion() const {
    return g_ISimsCounterTopObject_TypeVersion[0].ver[0];
}
