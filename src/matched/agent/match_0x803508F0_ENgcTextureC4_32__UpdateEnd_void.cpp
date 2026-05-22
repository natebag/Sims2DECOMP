// 0x803508F0 ENgcTextureC4_32::UpdateEnd(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x98(31); cmpwi 0,1; beq 2f; lwz 0,0x8(31); andi. 9,0,128; bne 1f; lhz 0,0x14(31); li 6,0; cmpw 6,0; bge 1f; li 5,0; 0:; lwz 7,0x90(31); add 10,6,6; lwz 11,0xcc(31); addi 6,6,1; add 8,7,5; lbz 0,0x1(8); stbx 0,10,11; lwz 9,0xcc(31); lbzx 0,7,5; add 9,10,9; addi 5,5,4; stb 0,0x1(9); lwz 11,0xd0(31); lbz 0,0x3(8); stbx 0,10,11; lwz 9,0xd0(31); lbz 11,0x2(8); add 10,10,9; stb 11,0x1(10); lhz 0,0x14(31); cmpw 6,0; blt 0b; 1:; lhz 4,0x14(31); lwz 3,0xcc(31); rlwinm 4,4,1,0,30; bl _s803508F0_0; lhz 4,0x14(31); lwz 3,0xd0(31); rlwinm 4,4,1,0,30; bl _s803508F0_1; 2:; mr 3,31; bl _s803508F0_2; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803508F0_0();
extern "C" void _s803508F0_1();
extern "C" void _s803508F0_2();
extern "C" void f_803508F0() {}
