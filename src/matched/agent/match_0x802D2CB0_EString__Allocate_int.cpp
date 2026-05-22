// 0x802D2CB0 EString::Allocate(int) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr. 30,4; beq 1f; bl _s802D2CB0_0; mr 29,3; cmpw 30,29; ble 2f; addi 4,30,1; mr 3,31; bl _s802D2CB0_1; mr. 30,3; beq 0f; lwz 4,0x0(31); addi 5,29,1; mr 3,30; crxor 6,6,6; bl _s802D2CB0_2; lwz 4,0x0(31); mr 3,31; bl _s802D2CB0_3; stw 30,0x0(31); b 2f; 0:; li 3,0; b 3f; 1:; mr 3,31; bl _s802D2CB0_4; 2:; li 3,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D2CB0_0();
extern "C" void _s802D2CB0_1();
extern "C" void _s802D2CB0_2();
extern "C" void _s802D2CB0_3();
extern "C" void _s802D2CB0_4();
extern "C" void f_802D2CB0() {}
