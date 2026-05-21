// 0x80307D74 EVibrate::IsControllerOn(unsigned char) (32B)

struct VibrateEntry {
    int m_field00;
    char pad[64];
};

class EVibrate {
    char pad[56];
    VibrateEntry m_controllers[2];
public:
    int IsControllerOn(unsigned char idx) const;
};

int EVibrate::IsControllerOn(unsigned char idx) const {
    if (idx > 1) return 0;
    return m_controllers[idx].m_field00;
}
