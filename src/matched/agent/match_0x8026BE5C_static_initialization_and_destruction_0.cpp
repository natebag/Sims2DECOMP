// 0x8026BE5C __static_initialization_and_destruction_0 (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 3,-32694; addi 3,3,-16288; bl _s8026BE5C_0; lis 10,-32700; lis 30,-32694; lhz 11,-6476(10); addi 9,30,-16116; li 28,0; li 6,512; addi 11,11,1; addi 7,10,-6476; sth 11,-6476(10); li 0,64; stw 28,0x3c(9); li 8,256; stw 7,-23024(13); li 29,384; stw 6,-16116(30); li 5,32; li 4,1024; li 3,128; stw 6,0x4(9); stw 29,0x20(9); stw 5,0x24(9); stw 8,0x28(9); stw 4,0x2c(9); stw 3,0x30(9); stw 0,0x34(9); stw 0,0x8(9); stw 8,0xc(9); stw 0,0x10(9); stw 8,0x14(9); stw 29,0x18(9); stw 0,0x1c(9); stw 28,0x38(9); b 1f; 0:; lwz 4,-23024(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026BE5C_1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8026BE5C_0();
extern "C" void _s8026BE5C_1();
extern "C" void f_8026BE5C() {}
