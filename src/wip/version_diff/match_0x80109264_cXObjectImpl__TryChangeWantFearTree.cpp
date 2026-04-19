// 0x80109264 (256B) cXObjectImpl::TryChangeWantFearTree(StackElem *, XPrimParam *)

struct StackElem;

struct XPrimParam {
    short f0;
    short f2;
    unsigned char f4;
};

struct Neighbor {
    int ForceNewTree(unsigned short id);
};

struct NSingleton {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual Neighbor* GetNeighbor(short id) = 0;
};

extern NSingleton* g_NSingleton;
extern int g_error_flag;

struct CObj {
    char pad[52];
    short field_52;
};

struct BehaviorNonVirtualBase { int pad0; };
struct Behavior : public BehaviorNonVirtualBase {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void FailErrorDispatch(int code) = 0;
};

struct cXObjectImpl {
    CObj* m_obj;
    Behavior* m_behavior;
    long long InterpValue(short, short, short**, float**, short*);
    long long TryChangeWantFearTree(StackElem*, XPrimParam*);
};

long long cXObjectImpl::TryChangeWantFearTree(StackElem* elem, XPrimParam* param) {
    short outResult;
    short p0 = param->f0;
    long long r = InterpValue(param->f4, param->f2, 0, 0, &outResult);
    if (r != -1LL) {
        Neighbor* n = g_NSingleton->GetNeighbor(outResult);
        if (n) {
            if (n->ForceNewTree((unsigned short)p0)) return 1;
            return 0;
        }
        {
            int err = 1;
            short code = 56;
            g_error_flag = err;
            m_obj->field_52 = code;
            m_behavior->FailErrorDispatch(code);
        }
    }
    return -1LL;
}
