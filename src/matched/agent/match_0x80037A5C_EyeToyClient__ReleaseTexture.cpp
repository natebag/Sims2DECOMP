// 0x80037A5C EyeToyClient::ReleaseTexture(ETexture*) (64B)

class ETexture;

class EManager {
public:
    virtual ~EManager() = 0;
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
    virtual void ReleaseTexture(ETexture* t) = 0;
};

extern EManager* g_eyetoy_mgr;

class EyeToyClient {
public:
    static void ReleaseTexture(ETexture* tex);
};

void EyeToyClient::ReleaseTexture(ETexture* tex) {
    if (tex == 0) return;
    g_eyetoy_mgr->ReleaseTexture(tex);
}
