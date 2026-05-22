// 0x8002BCB4 EIWallPart::~EIWallPart(void) (164B)

extern int EIWallPart_vt[];

class EResource {
public:
    void DelRef();
};

class ERLevel {
public:
    void RemoveWall(void* w);
};

class CTilePt {
public:
    void dtor_inline(int in_charge);
};

extern void CTilePt_dtor(void* self, int in_charge);
extern void EIStaticModel_dtor(void* self, int in_charge);
extern void EIWallPart_operator_delete(void* p);

class EIWallPart {
public:
    int* m_vt;          // 0
    void* m_field4;     // 4
    char pad_08[920];
    void* m_field928;   // 928
    void* m_field932;   // 932 (pad)
    EResource* m_res;   // 940
};

extern "C" void EIWallPart_dtor(EIWallPart* self, int in_charge) {
    char* s = (char*)self;
    EResource* res = *(EResource**)(s + 940);
    *(int**)(s + 0) = EIWallPart_vt;
    if (res != 0) {
        res->DelRef();
        *(void**)(s + 940) = 0;
    }
    void* f4 = *(void**)(s + 4);
    if (f4 != 0) {
        ((ERLevel*)f4)->RemoveWall(self);
    }
    EResource* f928 = *(EResource**)(s + 928);
    if (f928 != 0) {
        f928->DelRef();
        *(void**)(s + 928) = 0;
    }
    CTilePt_dtor(s + 808, 2);
    EIStaticModel_dtor(self, 0);
    if (in_charge & 1) {
        EIWallPart_operator_delete(self);
    }
}
