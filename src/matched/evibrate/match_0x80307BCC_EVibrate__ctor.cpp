// 0x80307BCC EVibrate::EVibrate(void) (88B)

extern "C" void* memset(void* dst, int c, unsigned int n);

extern char g_evibrate_aux[6];   // SDA r13-21312

class EVibrate {
public:
    int m_field_0;
    int m_field_4;
    char m_buf[136];   // 0x08-0x8F
    EVibrate();
};

EVibrate::EVibrate() {
    m_field_0 = 0;
    m_field_4 = 0;
    memset(m_buf, 0, 136);
    memset(g_evibrate_aux, 0, 6);
}
