// 0x802380B4 ERLevel::SafeDelete (64B)

struct ERLevel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERLevel();
    void SafeDelete();
};

void ERLevel::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
