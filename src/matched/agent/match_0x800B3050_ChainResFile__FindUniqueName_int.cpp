// 0x800B3050 ChainResFile::FindUniqueName(int, (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 26,4; mr 27,5; li 4,0; bl _s800B3050_0; mr 3,27; bl _s800B3050_1; cmpwi 3,0; bne 0f; lis 4,-32706; mr 3,27; addi 4,4,-26536; li 5,-1; bl _s800B3050_2; 0:; addi 3,31,16; li 30,0; lwzx 0,3,30; cmpwi 0,0; beq 2f; mr 31,3; li 28,0; li 29,0; 1:; lwzx 3,31,29; mr 4,26; mr 5,27; addi 30,30,1; lwz 9,0xc(3); addi 28,28,24; addi 29,29,24; lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 30,7; bgt 2f; lwzx 0,31,28; cmpwi 0,0; bne 1b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800B3050_0();
extern "C" void _s800B3050_1();
extern "C" void _s800B3050_2();
extern "C" void f_800B3050() {}
