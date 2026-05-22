// 0x8003E5C0 EGlobal::IsObjectInUseByPlayer(int, (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 28,5; cmpwi 4,1; bgt 1f; rlwinm 0,4,2,0,29; addi 9,31,188; lwzx 4,9,0; cmpwi 4,0; bne 0f; li 3,0; b 4f; 0:; lwz 9,0x4(4); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,4,3; blrl; bl _s8003E5C0_0; xor 3,3,28; subfic 0,3,0; adde 3,0,3; b 4f; 1:; lwz 11,0xbc(31); li 27,0; lwz 9,0x4(11); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0xc0(31); mr 30,3; lwz 9,0x4(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; mr 29,3; mr 3,30; bl _s8003E5C0_1; cmpw 3,28; beq 2f; lwz 0,0xc0(31); cmpwi 0,0; beq 3f; mr 3,29; bl _s8003E5C0_2; cmpw 3,28; bne 3f; 2:; li 27,1; 3:; mr 3,27; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8003E5C0_0();
extern "C" void _s8003E5C0_1();
extern "C" void _s8003E5C0_2();
extern "C" void f_8003E5C0() {}
