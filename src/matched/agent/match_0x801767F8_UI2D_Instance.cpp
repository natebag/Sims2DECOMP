// 0x801767F8 (60B) UI2D::Instance(void)

struct UI2D {
    char data[16];
    UI2D();
    static UI2D* Instance();
};

extern UI2D* g_ui2d_instance;

UI2D* UI2D::Instance() {
    if (!g_ui2d_instance) {
        g_ui2d_instance = new UI2D();
    }
    return g_ui2d_instance;
}
