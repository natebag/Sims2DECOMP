// 0x80160424 CasGenetics::~CasGenetics(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80160424_0; cmpwi 30,0; beq 2f; addi 31,30,32; 0:; cmpw 30,31; beq 2f; lwzu 3,-16(31); cmpwi 3,0; beq 0b; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 1f; bl _s80160424_1; b 0b; 1:; bl _s80160424_2; b 0b; 2:; andi. 0,29,1; beq 3f; mr 3,30; bl _s80160424_3; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80160424_0();
extern "C" void _s80160424_1();
extern "C" void _s80160424_2();
extern "C" void _s80160424_3();
extern "C" void f_80160424() {}
