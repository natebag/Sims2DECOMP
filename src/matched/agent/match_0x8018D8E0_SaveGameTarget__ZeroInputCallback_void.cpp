// 0x8018D8E0 SaveGameTarget::ZeroInputCallback(void) (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; lwz 0,0x12c(31); cmpwi 0,13; beq 4f; bgt 0f; cmpwi 0,0; beq 1f; b 6f; 0:; cmpwi 0,18; beq 5f; b 6f; 1:; lwz 0,0x138(31); andi. 9,0,8; beq 3f; lwz 3,0x128(31); li 29,1; stw 29,0x8(1); addi 4,1,8; bl _s8018D8E0_0; lwz 30,0x8(1); cmpwi 30,0; bne 2f; addi 3,31,132; bl _s8018D8E0_1; li 0,5; stw 30,0x130(31); stw 0,0x110(31); b 6f; 2:; stw 29,0x130(31); stw 29,0x12c(31); b 6f; 3:; li 0,1; stw 0,0x130(31); stw 0,0x12c(31); b 6f; 4:; li 0,0; li 11,14; li 9,1; stw 0,0x14c(31); stw 9,0x130(31); stw 11,0x12c(31); b 6f; 5:; li 9,19; li 0,1; stw 0,0x130(31); stw 9,0x12c(31); 6:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8018D8E0_0();
extern "C" void _s8018D8E0_1();
extern "C" void f_8018D8E0() {}
