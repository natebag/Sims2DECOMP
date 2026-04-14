// 0x8031B264 ERModel::SafeDelete (64B)

struct ERModel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERModel();
    void SafeDelete();
};

void ERModel::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
