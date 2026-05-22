// 0x800B23FC ChainResFile::GetLanguage(Memory::HandleNode (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 26,4; li 4,0; bl _s800B23FC_0; li 27,0; mr 3,29; li 4,-99; bl _s800B23FC_1; li 28,0; addi 9,29,16; lwzx 0,9,27; cmpwi 0,0; beq 1f; mr 31,9; li 30,0; 0:; lwzx 11,31,30; mr 4,26; lwz 9,0xc(11); lha 3,0xc0(9); lwz 0,0xc4(9); add 3,11,3; mtspr 8,0; blrl; mr 27,3; lwzx 3,31,30; bl _s800B23FC_2; mr 4,3; mr 3,29; bl _s800B23FC_3; lwzx 3,31,30; bl _s800B23FC_4; cmpwi 3,0; beq 1f; addi 28,28,1; addi 30,30,24; cmpwi 28,7; bgt 1f; lwzx 0,31,30; cmpwi 0,0; bne 0b; 1:; mr 3,27; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800B23FC_0();
extern "C" void _s800B23FC_1();
extern "C" void _s800B23FC_2();
extern "C" void _s800B23FC_3();
extern "C" void _s800B23FC_4();
extern "C" void f_800B23FC() {}
