/* ERTexture::SafeDelete(void) - 0x80321268 (64 bytes) */

struct ERTexture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERTexture();
    static void SafeDelete(ERTexture *p);
};

void ERTexture::SafeDelete(ERTexture *p)
{
    if (p) {
        delete p;
    }
}
