// 0x80054438 IShrubObject::GetTypeVersion (12B) const

struct VerBlock_IShrubObject { unsigned short ver[256]; };
extern VerBlock_IShrubObject g_IShrubObject_TypeVersion[3];

struct IShrubObject_GTV {
    unsigned short GetTypeVersion() const;
};

unsigned short IShrubObject_GTV::GetTypeVersion() const {
    return g_IShrubObject_TypeVersion[0].ver[0];
}
