// 0x801C1110 M2MTarget::SetDevice(int) (44B)
// Store dev@+268, call UIDB::UIDBSetInt("Device", dev)

extern char g_deviceKeyStr[16];  // non-SDA string at 0x803f21bc

struct M2MTarget {
    char pad[268];
    int m_device;
    void SetDevice(int dev);
};

namespace UIDB {
    void UIDBSetInt(char* key, int val);
}

void M2MTarget::SetDevice(int dev) {
    m_device = dev;
    UIDB::UIDBSetInt(g_deviceKeyStr, dev);
}
