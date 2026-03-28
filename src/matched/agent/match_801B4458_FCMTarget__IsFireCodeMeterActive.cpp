class FCMTarget {
public:
    char _pad[0x88];
    int m_isActive;

    int IsFireCodeMeterActive();
};

int FCMTarget::IsFireCodeMeterActive() {
    return m_isActive;
}
