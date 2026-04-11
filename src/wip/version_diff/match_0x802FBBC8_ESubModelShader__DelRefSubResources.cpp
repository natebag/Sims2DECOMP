struct EResource {
    void DelRef();
};

struct ESubModelShader {
    char pad[0x08];
    EResource *m_resource;

    void DelRefSubResources();
};

void ESubModelShader::DelRefSubResources() {
    if (m_resource != 0) {
        m_resource->DelRef();
    }
    m_resource = 0;
}
