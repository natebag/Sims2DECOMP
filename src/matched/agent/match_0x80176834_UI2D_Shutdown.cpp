// 0x80176834 (76B) UI2D::Shutdown(void) — MI-vcall slot 1 Destroy(3)

struct UI2D_Base { char pad[12]; };

struct UI2D_Impl : public UI2D_Base {
    virtual void Destroy(int mode) = 0;
};

extern UI2D_Impl* g_UI2D_instance;

struct UI2D {
    static void Shutdown();
};

void UI2D::Shutdown() {
    if (g_UI2D_instance) {
        g_UI2D_instance->Destroy(3);
        g_UI2D_instance = 0;
    }
}
