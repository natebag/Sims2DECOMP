// 0x8023FA28 DoFSReadHeader (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); li 11,24; addi 9,1,8; mtspr 9,11; li 0,0; 0:; stb 0,0x0(9); addi 9,9,1; bdnz 0b; lis 9,-32694; li 0,16; lwz 11,-26476(9); rlwinm 0,0,8,0,23; li 9,9; sth 0,0xa(1); cmpwi 11,0; stb 9,0x8(1); beq 1f; stb 9,0x10(1); b 2f; 1:; li 0,11; stb 0,0x10(1); 2:; stw 3,0x14(1); li 3,24; stw 6,0x18(1); stw 5,0x1c(1); bl _s8023FA28_0; addi 3,1,8; li 4,24; bl _s8023FA28_1; lwz 0,0x24(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s8023FA28_0();
extern "C" void _s8023FA28_1();
extern "C" void f_8023FA28() {}
