// 0x8030FB60 EREdithTreeSet::SafeDelete (64B)

struct EREdithTreeSet {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EREdithTreeSet();
    void SafeDelete();
};

void EREdithTreeSet::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
