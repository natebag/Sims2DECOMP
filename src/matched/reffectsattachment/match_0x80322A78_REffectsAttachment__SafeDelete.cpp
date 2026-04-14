// 0x80322A78 REffectsAttachment::SafeDelete (64B)

struct REffectsAttachment {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~REffectsAttachment();
    void SafeDelete();
};

void REffectsAttachment::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
