class WidgetScreenFormat {
public:
    int m_field0;
    int m_field4;
    char _pad[0x08];
    int m_field10;
    char _pad2[0x08];
    int m_field1C;

    WidgetScreenFormat(void);
};

WidgetScreenFormat::WidgetScreenFormat(void) {
    m_field0 = 0;
    m_field10 = 0;
    m_field1C = 0;
    m_field4 = 0;
}
