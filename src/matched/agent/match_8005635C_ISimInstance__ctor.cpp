// ISimInstance::ISimInstance(void)
// Address: 0x8005635C | Size: 200 bytes
// Frame: stwu -32(r1), stmw r30 at sp+24, lr at sp+36
// Float constants via separate 3-element arrays (forces lis+lfs, not sda21)
// Stack struct at sp+8 via pointer (forces addi r11, r1, 8)
// _LightVec: x=sp+8, y=sp+12, z=sp+16
//
// NEAR-MATCH: 12 instruction mismatches due to register allocation differences.
// The compiler computes ERRORLight's base register before ERRORLightCur's,
// using different register numbers (r8/r10 vs DOL's r7/r9 for the lis/addi).
// This causes all store ordering to differ in the global field writes section.
// Logic is correct; only register scheduling differs.

void EIStaticModel_ctor(void *p);
void EAnimController_ctor(void *p);

extern int ISimInstance_vtable[];
extern int ISimInstance_IBaseSimInstance_vtable[];

extern int ISimInstance__ERRORLightCur[62];
extern int ISimInstance__ERRORLight[3];

extern const float ISimInstance_c0_data[3];
extern const float ISimInstance_c1_data[3];

struct _LightVec { float x; float y; float z; };

class ISimInstance {
public:
    ISimInstance(void);
};

ISimInstance::ISimInstance(void) {
    EIStaticModel_ctor(this);
    *(int **)((char *)this + 0x320) = ISimInstance_IBaseSimInstance_vtable;
    *(int **)this = ISimInstance_vtable;
    EAnimController_ctor((char *)this + 0x334);
    _LightVec li;
    _LightVec *p = &li;
    li.x = ISimInstance_c0_data[0];
    p->y = ISimInstance_c1_data[0];
    p->z = ISimInstance_c1_data[0];
    int r10 = *(int *)&li.x;
    int r6  = *(int *)&p->z;
    int r8  = *(int *)&p->y;
    *(int *)((char *)this + 0x328) = 0;
    *(int *)((char *)this + 0x32C) = 0;
    ISimInstance__ERRORLightCur[0]  = r10;
    ISimInstance__ERRORLightCur[2]  = r6;
    ISimInstance__ERRORLight[0]     = r10;
    ISimInstance__ERRORLight[2]     = r6;
    ISimInstance__ERRORLightCur[1]  = r8;
    ISimInstance__ERRORLight[1]     = r8;
    ISimInstance__ERRORLightCur[61] = 0;
    ISimInstance__ERRORLightCur[60] = 0;
    *(int *)((char *)this + 0x3BC) = 0;
    *(int *)((char *)this + 0x3C0) = 0;
    *(int *)((char *)this + 0x3AC) = 0;
    *(int *)((char *)this + 0x3B0) = 0;
}
