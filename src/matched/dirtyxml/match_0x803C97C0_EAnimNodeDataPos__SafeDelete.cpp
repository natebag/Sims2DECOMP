// 0x803C97C0 EAnimNodeDataPos::SafeDelete(EAnimNodeDataPos*) (64B)

struct EAnimNodeDataPos {
    virtual void v4();
    virtual ~EAnimNodeDataPos();
    static void SafeDelete(EAnimNodeDataPos* p);
};

void EAnimNodeDataPos::SafeDelete(EAnimNodeDataPos* p) {
    if (p) {
        delete p;
    }
}
