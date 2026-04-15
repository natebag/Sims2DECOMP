// 0x80177038 (52B) UI3D::Instance(void)

struct UI3D {
    char data[32];
    UI3D();
    static UI3D* Instance();
};

extern UI3D* g_ui3d_instance;

UI3D* UI3D::Instance() {
    if (!g_ui3d_instance) {
        g_ui3d_instance = new UI3D();
    }
    return g_ui3d_instance;
}
