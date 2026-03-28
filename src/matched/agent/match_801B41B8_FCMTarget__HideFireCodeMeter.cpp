class FCMTarget {
public:
    char _pad[0x90];
    int m_showMeter;

    void HideFireCodeMeter();
};

void FCMTarget::HideFireCodeMeter() {
    m_showMeter = 0;
}
