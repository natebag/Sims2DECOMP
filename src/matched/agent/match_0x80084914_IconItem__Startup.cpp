struct IconItem {
    char pad[0x30];
    int m_shader;

    void Startup(void);
};

void IconItem::Startup(void) {
    m_shader = 0;
}
