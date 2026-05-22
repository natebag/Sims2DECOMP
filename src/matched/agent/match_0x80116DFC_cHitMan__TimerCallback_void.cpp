// 0x80116DFC cHitMan::TimerCallback(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 30,3; lwz 0,0x1c(30); cmpwi 0,0; beq 5f; lwz 9,0x3c(30); addi 11,30,16; lwz 0,0x10(30); addi 9,9,1; stw 9,0x3c(30); cmpwi 0,0; beq 0f; lwz 9,0x4(11); addi 9,9,1; stw 9,0x4(11); 0:; addi 9,30,4; lwz 11,0x4(9); lwz 0,0x0(11); stw 0,0xc(30); stw 0,0x8(1); mr 29,9; b 3f; 1:; stw 3,0x8(1); lwz 31,0x8(3); cmpwi 31,0; beq 2f; lwz 9,-24136(13); mr 4,31; lwz 3,0x50(9); bl _s80116DFC_0; cmpwi 3,0; beq 2f; mr 3,31; bl _s80116DFC_1; 2:; lwz 9,0xc(30); lwz 0,0x8(1); cmpw 9,0; bne 3f; stw 9,0x18(1); lwz 0,0x0(9); stw 9,0x10(1); stw 0,0xc(30); 3:; lwz 0,0x4(29); li 9,1; lwz 3,0xc(30); stw 0,0x8(1); cmpw 3,0; bne 4f; li 9,0; 4:; cmpwi 9,0; bne 1b; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s80116DFC_0();
extern "C" void _s80116DFC_1();
extern "C" void f_80116DFC() {}
