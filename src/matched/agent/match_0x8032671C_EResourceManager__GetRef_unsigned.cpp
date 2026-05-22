// 0x8032671C EResourceManager::GetRef(unsigned (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr. 30,4; beq 1f; stw 31,0x8(1); li 4,-1; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; addi 3,31,3336; mr 4,30; addi 5,1,12; bl _s8032671C_0; cmpwi 3,0; beq 0f; lwz 31,0xc(1); lha 0,0xc(31); cmpwi 0,0; beq 0f; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,31; b 2f; 0:; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8032671C_0();
extern "C" void f_8032671C() {}
