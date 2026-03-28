/* SkinCompositor::~SkinCompositor(void) - 0x80075B70 (64 bytes) */

struct SkinCompositor {
    void Cleanup();
    ~SkinCompositor();
};

SkinCompositor::~SkinCompositor()
{
    Cleanup();
}
