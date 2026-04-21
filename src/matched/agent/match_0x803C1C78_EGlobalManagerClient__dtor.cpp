// 0x803C1C78 EGlobalManagerClient::~EGlobalManagerClient (76B)
// dtor: vtable@+0 + bl Shutdown + delete-flag check.

extern int VT_EGlobalManagerClient[];

struct EGlobalManagerClient {
    int* m_vtable;
    void Shutdown();
    ~EGlobalManagerClient();
};

EGlobalManagerClient::~EGlobalManagerClient() {
    m_vtable = VT_EGlobalManagerClient;
    Shutdown();
}
