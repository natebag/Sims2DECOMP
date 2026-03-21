// simulator_large.cpp - cSimulatorImpl large functions (257-512 bytes)
// Object file: simulator.obj
// Functions: Init, DoCommand, SetFunds
// All NON_MATCHING - vtable dispatch, SDA addressing, register allocation

#include "types.h"

extern "C" {
    void* operator_new_wrapper(unsigned int size);
    void Globs_InitSomething(void);
    void PassiveInfluenceSystem_Create(void);
    extern short g_simSpeedSDA;
}

// 0x80140324 - 296 bytes - cSimulatorImpl::Init(void)
// NON_MATCHING - vtable dispatch patterns, SDA addressing
void cSimulatorImpl_Init(void* self) {
    char* _this = (char*)self;
    short* globals = (short*)(_this + 0x14);
    for (short i = 0; i < 47; i++) { globals[i] = 0; }
    *(int*)(_this + 0x84) = 3500;
    *(short*)(_this + 0x22) = 6;
    *(short*)(_this + 0x24) = 1997;
    *(short*)(_this + 0x34) = 2;
    *(short*)(_this + 0x16) = 15;
    *(short*)(_this + 0x1e) = 0;
    *(int*)(_this + 0x8c) = 0;
    *(int*)(_this + 0x88) = 0;
    *(int*)(_this + 0x9c) = 0;
    *(int*)(_this + 0x178) = 0;
    *(int*)(_this + 0x7c) = 0;
    *(int*)(_this + 0x74) = 0;
    *(int*)(_this + 0x78) = 0;
    *(short*)(_this + 0x14) = 1;
    void** vtbl = *(void***)_this;
    typedef short (*GetTODFn)(void*);
    short adj = *(short*)((char*)vtbl + 0x190);
    GetTODFn fn = (GetTODFn)*((void**)((char*)vtbl + 0x194));
    short tod = fn(_this + adj);
    *(short*)(_this + 0x1c) = tod;
    *(short*)(_this + 0x38) = -1;
    *(short*)(_this + 0x36) = 1;
    *(short*)(_this + 0x2c) = 4;
    *(short*)(_this + 0x68) = 255;
    *(short*)(_this + 0x62) = -1;
    Globs_InitSomething();
    vtbl = *(void***)_this;
    typedef void (*InitFn2)(void*, int);
    short adj2 = *(short*)((char*)vtbl + 0x40);
    InitFn2 fn2 = (InitFn2)*((void**)((char*)vtbl + 0x44));
    fn2(_this + adj2, 0);
    *(short*)(_this + 0x3c) = 3;
    void* mem = operator_new_wrapper(24);
    PassiveInfluenceSystem_Create();
    *(void**)(_this + 0x174) = mem;
    g_simSpeedSDA = 4;
}

// 0x80140818 - 268 bytes - cSimulatorImpl::DoCommand(short, int)
// NON_MATCHING - switch/case codegen
int cSimulatorImpl_DoCommand(void* self, short cmd, int param) {
    char* _this = (char*)self;
    switch (cmd) {
    case 205: {
        void** vtbl = *(void***)_this;
        short adj = *(short*)((char*)vtbl + 0x18);
        void (*fn)(void*) = (void(*)(void*))*(void**)((char*)vtbl + 0x1c);
        fn(_this + adj);
        break;
    }
    case 135: {
        int val = *(int*)(_this + 0x178);
        if (val != param) return 0;
        *(int*)(_this + 0x178) = param + 1;
        break;
    }
    case 218: {
        void** vtbl = *(void***)_this;
        typedef int (*GetFn)(void*, int);
        short adj1 = *(short*)((char*)vtbl + 0xa0);
        GetFn fn1 = (GetFn)*((void**)((char*)vtbl + 0xa4));
        int result = fn1(_this + adj1, 0);
        short adj2 = *(short*)((char*)vtbl + 0xd0);
        typedef void (*SetFn)(void*, int, int);
        SetFn fn2 = (SetFn)*((void**)((char*)vtbl + 0xd4));
        fn2(_this + adj2, result + param, 0);
        break;
    }
    case 224: *(short*)(_this + 0x1a) = (short)param; break;
    case 265: *(short*)(_this + 0x54) = (short)param; break;
    case 244: *(short*)(_this + 0x18) = (short)param; break;
    default: return 0;
    }
    return 1;
}

// 0x801413ec - 288 bytes - cSimulatorImpl::SetFunds(int, int)
// NON_MATCHING - division by constant, vtable dispatch, SDA globals
void cSimulatorImpl_SetFunds(void* self, int newFunds, int player) {
    char* _this = (char*)self;
    int funds = *(int*)(_this + 0x74);
    int pending = *(int*)(_this + 0x78);
    int currentFunds = funds + pending;
    if (newFunds == currentFunds) return;
    int delta = newFunds - funds;
    int total = funds + delta;
    *(int*)(_this + 0x78) = delta;
    if (total > 999999) {
        delta = 999999 - funds;
        *(int*)(_this + 0x78) = delta;
        newFunds = funds + delta;
    }
    int high = newFunds / 10000;
    int low = newFunds - (high * 10000);
    *(short*)(_this + 0x30) = (short)high;
    *(short*)(_this + 0x2e) = (short)low;
    int change = delta - pending;
    if (change <= 0) return;
    // Post expense notifications via vtable dispatches (stubbed)
}
