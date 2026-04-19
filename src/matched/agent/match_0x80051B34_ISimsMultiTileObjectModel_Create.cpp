// 0x80051B34 (96B) ISimsMultiTileObjectModel::Create(cXObject*, EHouse*)
// Store args, call own SetObjOrient, call base SetInitalObjectState, then virtual if flag set.

struct cXObject;
struct EHouse;

struct ISimsObjectModel {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void PostCreate() = 0;
    void SetInitalObjectState();
};

struct ISimsMultiTileObjectModel : public ISimsObjectModel {
    char pad1[0x11c];
    int flag;
    char pad2[0x204];
    cXObject* xobj;
    char pad3[0x9c];
    EHouse* house;

    void SetObjOrient();
    void Create(cXObject* x, EHouse* h);
};

void ISimsMultiTileObjectModel::Create(cXObject* x, EHouse* h) {
    this->xobj = x;
    this->house = h;
    this->SetObjOrient();
    this->SetInitalObjectState();
    if (this->flag) {
        this->PostCreate();
    }
}
