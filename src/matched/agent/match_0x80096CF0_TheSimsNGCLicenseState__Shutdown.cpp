struct EResource {
    void DelRef();
};

struct TheSimsNGCLicenseState {
    char pad[0x1C];
    EResource *m_resource;

    void Shutdown();
};

void TheSimsNGCLicenseState::Shutdown() {
    if (m_resource != 0) {
        m_resource->DelRef();
    }
    m_resource = 0;
}
