// 0x800B2ECC ChainResFile::IsLittleEndian(Memory::HandleNode (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 27,4; li 4,0; bl _s800B2ECC_0; li 29,0; mr 3,28; li 4,-99; bl _s800B2ECC_1; addi 3,28,16; lwzx 0,3,29; cmpwi 0,0; beq 2f; mr 31,3; 0:; lwz 3,0x0(31); mr 4,27; lwz 9,0xc(3); lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; mtspr 8,9; blrl; mr 30,3; lwz 3,0x0(31); bl _s800B2ECC_2; cmpwi 3,0; bne 1f; mr 3,28; li 4,0; bl _s800B2ECC_3; mr 3,30; b 3f; 1:; addi 29,29,1; addi 31,31,24; cmpwi 29,7; bgt 2f; lwz 0,0x0(31); cmpwi 0,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800B2ECC_0();
extern "C" void _s800B2ECC_1();
extern "C" void _s800B2ECC_2();
extern "C" void _s800B2ECC_3();
extern "C" void f_800B2ECC() {}
