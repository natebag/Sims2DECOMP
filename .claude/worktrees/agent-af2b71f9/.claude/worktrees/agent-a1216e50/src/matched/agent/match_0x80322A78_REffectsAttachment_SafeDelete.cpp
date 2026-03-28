/* REffectsAttachment::SafeDelete(void) - 0x80322A78 (64 bytes) */

struct REffectsAttachment {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~REffectsAttachment();
    static void SafeDelete(REffectsAttachment *p);
};

void REffectsAttachment::SafeDelete(REffectsAttachment *p)
{
    if (p) {
        delete p;
    }
}
