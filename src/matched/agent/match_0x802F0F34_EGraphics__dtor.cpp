// 0x802F0F34 EGraphics::~EGraphics(void) (76B)
// Sibling-port from 0x803C1C78 EGlobalManagerClient::~EGlobalManagerClient.
// Inherits from EGlobalManagerClient; calls base Shutdown(); compiler-generated delete-flag handler.

extern int VT_EGraphics[];

struct EGlobalManagerClient {
    int* m_vtable;
    void Shutdown();
};

struct EGraphics : public EGlobalManagerClient {
    ~EGraphics();
};

EGraphics::~EGraphics() {
    m_vtable = VT_EGraphics;
    EGlobalManagerClient::Shutdown();
}
