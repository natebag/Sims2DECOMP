class INGTarget {
public:
    struct TabInfo {
        int m_field0;
        short m_field4;
        char _pad[2];
        int m_field8;

        TabInfo();
    };
};

INGTarget::TabInfo::TabInfo() {
    m_field0 = 0;
    m_field4 = 0;
    m_field8 = 0;
}
