// 0x80029B94 EIFenceWall::~EIFenceWall(void) (144B)

extern int EIFenceWall_vt[];

class ERLevel {
public:
    void RemoveWall(void* w);
};

class EResource {
public:
    void DelRef();
};

extern void EIWallPart_dtor(void* self, int in_charge);
extern void* MainHeap();
extern void HeapDelete(void* heap, void* p);

extern int g_eifenceCounter;  // SDA -32640

class EIFenceWall {
public:
    int* m_vt;            // 0
    void* m_field4;       // 4
    char pad_08[932];
    EResource* m_res;     // 940
};

extern "C" void EIFenceWall_dtor(EIFenceWall* self, int in_charge) {
    char* s = (char*)self;
    int cnt = g_eifenceCounter;
    void* f4 = *(void**)(s + 4);
    *(int**)(s + 0) = EIFenceWall_vt;
    g_eifenceCounter = cnt - 1;
    if (f4 != 0) {
        ((ERLevel*)f4)->RemoveWall(self);
    }
    EResource* res = *(EResource**)(s + 940);
    if (res != 0) {
        res->DelRef();
        *(void**)(s + 940) = 0;
    }
    EIWallPart_dtor(self, 0);
    if (in_charge & 1) {
        HeapDelete(MainHeap(), self);
    }
}
