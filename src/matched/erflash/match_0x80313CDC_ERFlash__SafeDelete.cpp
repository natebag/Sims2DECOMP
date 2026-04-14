// 0x80313CDC ERFlash::SafeDelete (64B)

struct ERFlash {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERFlash();
    void SafeDelete();
};

void ERFlash::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
