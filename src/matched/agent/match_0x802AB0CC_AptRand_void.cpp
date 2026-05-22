// 0x802AB0CC AptRand(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-27100(13); addi 9,9,-1; cmpwi 9,0; stw 9,-27100(13); blt 0f; addi 8,13,-22976; lis 10,-25300; lwz 9,0x0(8); ori 10,10,22144; lwz 3,0x0(9); addi 9,9,4; rlwinm 11,3,21,11,31; stw 9,0x0(8); xor 3,3,11; rlwinm 0,3,7,0,24; and 0,0,10; xor 3,3,0; rlwinm 9,3,15,0,16; andis. 9,9,61382; xor 3,3,9; rlwinm 0,3,14,18,31; xor 3,3,0; b 1f; 0:; bl _s802AB0CC_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802AB0CC_0();
extern "C" void f_802AB0CC() {}
