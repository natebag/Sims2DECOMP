// 0x80147198 TreeStack::~TreeStack(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x0(31); cmpwi 0,0; beq 0f; bl _s80147198_0; lwz 4,0x0(31); bl _s80147198_1; 0:; lwz 3,0x8(31); li 0,0; stw 0,0x0(31); addi 9,31,8; cmpwi 3,0; beq 2f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 1f; bl _s80147198_2; b 2f; 1:; bl _s80147198_3; 2:; andi. 0,30,1; beq 3f; mr 3,31; bl _s80147198_4; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80147198_0();
extern "C" void _s80147198_1();
extern "C" void _s80147198_2();
extern "C" void _s80147198_3();
extern "C" void _s80147198_4();
extern "C" void f_80147198() {}
