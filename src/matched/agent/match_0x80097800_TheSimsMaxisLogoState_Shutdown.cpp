// 0x80097800 (80B) TheSimsMaxisLogoState::Shutdown(void)

struct LogoResource_Data { char pad[128]; };
struct LogoResource_Impl : public LogoResource_Data {
    virtual void Destroy(int flag) = 0;
};

extern void ProcessLogo(LogoResource_Impl* r);

struct TheSimsMaxisLogoState {
    char pad[28];
    LogoResource_Impl* m_resource;
    int m_flag;

    void Shutdown();
};

void TheSimsMaxisLogoState::Shutdown() {
    ProcessLogo(m_resource);
    if (m_resource) m_resource->Destroy(3);
    m_resource = 0;
    m_flag = 0;
}
