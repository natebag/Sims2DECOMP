// 0x80350EE4 ENgcTextureC8_32::Create(ETextureDef (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,4; bl _s80350EE4_0; mr. 28,3; beq 1f; lwz 0,0x8(31); andi. 9,0,128; beq 0f; lwz 9,0x90(31); stw 9,0xcc(31); lhz 0,0x14(29); add 0,0,0; add 9,9,0; stw 9,0xd0(31); b 1f; 0:; lhz 4,0x14(29); lis 30,-32692; li 5,32; addi 3,30,-7364; rlwinm 4,4,1,0,30; bl _s80350EE4_1; stw 3,0xcc(31); li 5,32; addi 3,30,-7364; lhz 4,0x14(29); rlwinm 4,4,1,0,30; bl _s80350EE4_2; stw 3,0xd0(31); 1:; mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80350EE4_0();
extern "C" void _s80350EE4_1();
extern "C" void _s80350EE4_2();
extern "C" void f_80350EE4() {}
