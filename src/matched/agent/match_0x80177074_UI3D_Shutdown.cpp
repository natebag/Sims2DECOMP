// 0x80177074 (76B) UI3D::Shutdown(void) — MI-vcall slot 1 Destroy(3)

struct UI3D_Base { char pad[28]; };

struct UI3D_Impl : public UI3D_Base {
    virtual void Destroy(int mode) = 0;
};

extern UI3D_Impl* g_UI3D_instance;

struct UI3D {
    static void Shutdown();
};

void UI3D::Shutdown() {
    if (g_UI3D_instance) {
        g_UI3D_instance->Destroy(3);
        g_UI3D_instance = 0;
    }
}
