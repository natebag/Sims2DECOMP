// 0x80037B40 EyeToyClient::ReleaseRenderSurface(ERenderSurface*) (64B)

class ERenderSurface;

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
    virtual void ReleaseTexture(void* t) = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void ReleaseRenderSurface(ERenderSurface* s) = 0;
};

extern EManager* g_eyetoy_mgr;

class EyeToyClient {
public:
    static void ReleaseRenderSurface(ERenderSurface* surf);
};

void EyeToyClient::ReleaseRenderSurface(ERenderSurface* surf) {
    if (surf == 0) return;
    g_eyetoy_mgr->ReleaseRenderSurface(surf);
}
