// 0x8029E474 AptLoader::Invalidate(AptFile (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; lwz 9,0x0(31); stw 9,0x8(1); lwz 0,0x0(9); cmpw 0,4; bne 0f; cmpwi 9,0; beq 8f; lwz 3,-23020(13); mr 4,9; lwz 30,0x4(9); li 5,8; bl _s8029E474_0; stw 30,0x0(31); b 8f; 0:; stw 9,0x8(1); li 10,0; b 6f; 1:; stw 9,0x10(1); li 11,0; li 0,1; lwz 9,0x4(9); stw 10,0x18(1); stw 9,0x10(1); cmpwi 9,0; bne 2f; li 0,0; 2:; cmpwi 0,0; beq 3f; lwz 0,0x0(9); cmpw 0,4; bne 3f; li 11,1; 3:; cmpwi 11,0; beq 5f; lwz 9,0x8(1); lwz 4,0x4(9); cmpwi 4,0; beq 4f; lwz 0,0x4(4); stw 0,0x4(9); 4:; lwz 3,-23020(13); li 5,8; bl _s8029E474_1; b 8f; 5:; lwz 9,0x8(1); lwz 0,0x4(9); stw 0,0x8(1); 6:; lwz 9,0x8(1); li 0,1; stw 10,0x10(1); cmpwi 9,0; bne 7f; li 0,0; 7:; cmpwi 0,0; bne 1b; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s8029E474_0();
extern "C" void _s8029E474_1();
extern "C" void f_8029E474() {}
