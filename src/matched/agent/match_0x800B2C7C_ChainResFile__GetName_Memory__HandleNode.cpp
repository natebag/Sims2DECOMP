// 0x800B2C7C ChainResFile::GetName(Memory::HandleNode (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; mr 26,4; mr 27,5; li 4,0; li 29,0; bl _s800B2C7C_0; mr 3,28; li 4,-99; bl _s800B2C7C_1; addi 9,28,16; lwzx 0,9,29; cmpwi 0,0; beq 1f; mr 31,9; li 30,0; 0:; lwzx 11,31,30; mr 5,27; mr 4,26; lwz 9,0xc(11); lha 3,0xa0(9); lwz 0,0xa4(9); add 3,11,3; mtspr 8,0; blrl; lwzx 3,31,30; bl _s800B2C7C_2; mr 4,3; mr 3,28; bl _s800B2C7C_3; lwzx 3,31,30; bl _s800B2C7C_4; cmpwi 3,0; beq 1f; addi 29,29,1; addi 30,30,24; cmpwi 29,7; bgt 1f; lwzx 0,31,30; cmpwi 0,0; bne 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800B2C7C_0();
extern "C" void _s800B2C7C_1();
extern "C" void _s800B2C7C_2();
extern "C" void _s800B2C7C_3();
extern "C" void _s800B2C7C_4();
extern "C" void f_800B2C7C() {}
