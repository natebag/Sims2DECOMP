// 0x8022F8A0 {anonymous}::CasDummy2::~CasDummy2(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,0x14(1); mr 30,3; bl _s8022F8A0_0; mr 4,30; li 5,16; li 6,0; li 7,0; bl _s8022F8A0_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8022F8A0_0();
extern "C" void _s8022F8A0_1();
extern "C" void f_8022F8A0() {}
