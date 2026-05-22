// 0x80078C44 CUnlockDisplay::ObjectHasMultiColor(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x464(3); li 3,0; cmpwi 31,0; beq 3f; 0:; cmpwi 3,0; li 30,0; bne 1f; mr 3,31; bl _s80078C44_0; bl _s80078C44_1; cmpwi 3,0; beq 2f; 1:; li 30,1; 2:; lwz 31,0x0(31); mr 3,30; cmpwi 31,0; bne 0b; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80078C44_0();
extern "C" void _s80078C44_1();
extern "C" void f_80078C44() {}
