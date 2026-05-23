/* WXFTarget::Deallocate() at 0x80313484 (68 bytes) */

typedef unsigned int u32;

void ReleaseResource(u32 resource, int mode);

struct WXFTargetBase {
    char _pad[0x14];
    u32 m_resource;

    void Deallocate();
};

void WXFTargetBase::Deallocate()
{
    if (m_resource != 0) {
        ReleaseResource(m_resource, 3);
        m_resource = 0;
    }
}
