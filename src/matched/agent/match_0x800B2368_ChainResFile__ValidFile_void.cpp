// 0x800B2368 ChainResFile::ValidFile(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,0; li 31,0; bl _s800B2368_0; addi 3,30,16; lwzx 0,3,31; cmpwi 0,0; beq 2f; mr 30,3; 0:; lwz 3,0x0(30); lwz 9,0xc(3); lha 0,0x60(9); lwz 9,0x64(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; li 3,1; b 3f; 1:; addi 31,31,1; addi 30,30,24; cmpwi 31,7; bgt 2f; lwz 0,0x0(30); cmpwi 0,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B2368_0();
extern "C" void f_800B2368() {}
