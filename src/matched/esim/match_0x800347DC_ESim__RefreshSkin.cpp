// 0x800347DC ESim::RefreshSkin (132b)
// FLAGS: -fno-elide-constructors

struct SkinObj {
    int _vt_pad;
    virtual void V0();  virtual void V1();  virtual void V2();  virtual void V3();
    virtual void V4();  virtual void V5();  virtual void V6();  virtual void V7();
    virtual void V8();  virtual void V9();  virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24(); virtual void V25(); virtual void V26(); virtual void V27();
    virtual void V28(); virtual void V29(); virtual void V30(); virtual void V31();
    virtual void V32(); virtual void V33(); virtual void V34(); virtual void V35();
    virtual void V36(); virtual void V37(); virtual void V38(); virtual void V39();
    virtual void V40(); virtual void V41(); virtual void V42();
    virtual void* V43();
};

extern void RefreshAnimCtrl(void*);

struct ESim {
    char pad_00[0x334];
    char animator[4];
    char pad_338[0x3D0 - 0x338];
    SkinObj* skinObj;
    char pad_3D4[4];
    int skinState;
    char pad_3DC[0x630 - 0x3DC];
    int skinHandle;

    void RefreshSkin();
    int HasQueuedOperation();
};

void ESim::RefreshSkin() {
    SkinObj* skin = skinObj;
    if (skin != 0) {
        void* result = skin->V43();
        if (result == 0) {
            if (HasQueuedOperation() == 0) {
                if (skinHandle == -1) {
                    skinHandle = 0;
                    skinState = 1;
                    RefreshAnimCtrl(&animator);
                }
            }
        }
    }
}
