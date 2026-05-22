// 0x80110424 ObjResFile::Open(StringBuffer&) (88B)

class StringBuffer;

class IObjResMgr {
public:
    virtual ~IObjResMgr() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void NotifyOpened(class ObjResFile* file) = 0;
};

extern IObjResMgr* g_obj_res_mgr;

class StdResFile {
public:
    int Open(StringBuffer& name);
};

class ObjResFile : public StdResFile {
public:
    int Open(StringBuffer& name);
};

int ObjResFile::Open(StringBuffer& name) {
    int result = StdResFile::Open(name);
    if (result == 0) {
        g_obj_res_mgr->NotifyOpened(this);
    }
    return result;
}
