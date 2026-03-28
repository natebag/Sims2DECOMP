class FCMTarget {
public:
    char _pad[0xA0];
    int m_meterHeight;

    void SetMeterHeight(int height);
};

void FCMTarget::SetMeterHeight(int height) {
    if (height < 0) {
        m_meterHeight = 0;
    } else if (height > 100) {
        m_meterHeight = 100;
    } else {
        m_meterHeight = height;
    }
}
