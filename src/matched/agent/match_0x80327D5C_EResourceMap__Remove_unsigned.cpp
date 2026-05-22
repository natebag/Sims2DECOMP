// 0x80327D5C EResourceMap::Remove(unsigned (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s80327D5C_0; lwz 9,0x0(31); rlwinm 10,3,3,0,28; lwzx 0,10,9; add 11,10,9; cmpw 0,30; beq 0f; li 3,0; b 3f; 0:; lwz 11,0x4(11); li 0,0; stw 0,0x4(11); lwz 9,0x4(31); addi 9,9,-1; cmpw 3,9; bge 2f; mr 8,10; 1:; lwz 10,0x0(31); addi 3,3,1; add 10,8,10; lwz 11,0x8(10); lwz 12,0xc(10); addi 8,8,8; stw 11,0x0(10); stw 12,0x4(10); lwz 9,0x4(31); addi 9,9,-1; cmpw 3,9; blt 1b; 2:; lwz 9,0x4(31); li 8,0; lwz 10,0x0(31); li 3,1; addi 9,9,-1; stw 9,0x4(31); rlwinm 11,9,3,0,28; stwx 8,11,10; lwz 9,0x4(31); lwz 0,0x0(31); rlwinm 9,9,3,0,28; add 9,9,0; stw 8,0x4(9); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80327D5C_0();
extern "C" void f_80327D5C() {}
