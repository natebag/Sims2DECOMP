// 0x800B3570 ChainResFile::Write(Memory::HandleNode (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 28,4; li 4,0; bl _s800B3570_0; li 30,0; mr 3,29; li 4,-99; bl _s800B3570_1; addi 3,29,16; lwzx 0,3,30; cmpwi 0,0; beq 2f; mr 31,3; 0:; lwz 3,0x0(31); lwz 9,0xc(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; lwz 11,0x0(31); mr 4,28; lwz 9,0xc(11); lha 3,0x108(9); lwz 0,0x10c(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,0x0(31); bl _s800B3570_2; mr 4,3; mr 3,29; bl _s800B3570_3; lwz 3,0x0(31); bl _s800B3570_4; cmpwi 3,0; beq 2f; 1:; addi 30,30,1; addi 31,31,24; cmpwi 30,7; bgt 2f; lwz 0,0x0(31); cmpwi 0,0; bne 0b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800B3570_0();
extern "C" void _s800B3570_1();
extern "C" void _s800B3570_2();
extern "C" void _s800B3570_3();
extern "C" void _s800B3570_4();
extern "C" void f_800B3570() {}
