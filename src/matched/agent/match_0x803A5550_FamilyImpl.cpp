// 0x803A5550 FamilyImpl (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 31,4; mr 28,5; mr 29,6; 0:; addi 31,31,-4; b 2f; 1:; addi 30,30,4; 2:; mr 3,30; addi 4,1,8; mtspr 8,29; stw 28,0x8(1); blrl; cmpwi 3,0; bne 1b; b 4f; 3:; addi 31,31,-4; 4:; addi 3,1,8; mr 4,31; mtspr 8,29; stw 28,0x8(1); blrl; cmpwi 3,0; bne 3b; cmplw 30,31; bge 5f; lwz 0,0x0(31); lwz 9,0x0(30); stw 0,0x0(30); stw 9,0x0(31); addi 30,30,4; b 0b; 5:; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void f_803A5550() {}
