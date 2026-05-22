// 0x800779A0 CUnlockDisplay::destroyObjects(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 11,0x464(30); cmpwi 11,0; beq 2f; 0:; lwz 31,0x0(11); cmpwi 11,0; beq 1f; lwz 9,0x84(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; mr. 11,31; bne 0b; 2:; li 0,0; stw 0,0x464(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_800779A0() {}
