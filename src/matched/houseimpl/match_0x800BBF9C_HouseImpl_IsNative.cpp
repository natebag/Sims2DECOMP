// HouseImpl::IsNative(cXPerson *) at 0x800BBF9C (112B)
// MI vtable dispatch pattern (like HouseImpl::PrepareForBudgetWindow)

typedef unsigned char u8;
class cXPerson;

extern u8* g_simMgrHouse;  // at -21424(r13)

class HouseImpl {
public:
    int IsNative(cXPerson* person);
};

int HouseImpl::IsNative(cXPerson* person) {
    u8* mgr = g_simMgrHouse;
    u8* vt1 = *(u8**)mgr;
    short adj1 = *(short*)(vt1 + 0x38);
    u8* (*func1)(u8*) = *(u8* (**)(u8*))(vt1 + 0x3C);
    u8* obj = func1(mgr + adj1);

    u8* vt2 = *(u8**)obj;
    short adj2 = *(short*)(vt2 + 0x50);
    int (*func2)(u8*, cXPerson*) = *(int (**)(u8*, cXPerson*))(vt2 + 0x54);
    int result = func2(obj + adj2, person);

    if (result != 0) return 1;
    return 0;
}
