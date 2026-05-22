// 0x803A06B4 Wrapper::~Wrapper(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,-12392; stw 9,0x80(31); mr 30,4; bl _s803A06B4_0; lwz 3,0x8c(31); addi 9,31,140; cmpwi 3,0; beq 1f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s803A06B4_1; b 1f; 0:; bl _s803A06B4_2; 1:; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 2f; mr 3,31; bl _s803A06B4_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803A06B4_0();
extern "C" void _s803A06B4_1();
extern "C" void _s803A06B4_2();
extern "C" void _s803A06B4_3();
extern "C" void f_803A06B4() {}
