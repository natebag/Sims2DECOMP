// 0x8003ACFC GetObjectMenuName(cXObject (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; lwz 9,0x4(30); lha 3,0x368(9); lwz 0,0x36c(9); add 3,30,3; mtspr 8,0; blrl; mr 31,3; bl _s8003ACFC_0; cmpwi 3,0; beq 0f; mr 3,31; bl _s8003ACFC_1; bl _s8003ACFC_2; b 3f; 0:; lwz 9,0x4(30); lha 3,0x390(9); lwz 0,0x394(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; addi 30,1,8; mr 3,31; bl _s8003ACFC_3; mr 4,3; mr 3,30; crxor 6,6,6; bl _s8003ACFC_4; lwz 9,0x8(1); b 2f; 1:; addi 3,1,12; mr 4,31; crxor 6,6,6; bl _s8003ACFC_5; lwz 9,0xc(1); 2:; li 3,0; cmpwi 9,0; beq 3f; lwz 3,0x0(9); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8003ACFC_0();
extern "C" void _s8003ACFC_1();
extern "C" void _s8003ACFC_2();
extern "C" void _s8003ACFC_3();
extern "C" void _s8003ACFC_4();
extern "C" void _s8003ACFC_5();
extern "C" void f_8003ACFC() {}
