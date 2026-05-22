// 0x801C2D80 M2MTarget::UnloadDialog(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 11,0x118(30); cmpwi 11,0; beq 0f; lwz 9,0x8(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 0,0; mr 3,30; stw 0,0x118(30); addi 31,30,312; bl _s801C2D80_0; li 29,0; lis 9,-32697; li 4,48; lwz 3,0x5f10(9); bl _s801C2D80_1; addi 3,30,308; li 4,0; li 5,-1; bl _s801C2D80_2; 1:; mr 3,31; li 4,0; li 5,-1; addi 29,29,1; bl _s801C2D80_3; addi 31,31,4; cmplwi 29,7; ble 1b; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C2D80_0();
extern "C" void _s801C2D80_1();
extern "C" void _s801C2D80_2();
extern "C" void _s801C2D80_3();
extern "C" void f_801C2D80() {}
