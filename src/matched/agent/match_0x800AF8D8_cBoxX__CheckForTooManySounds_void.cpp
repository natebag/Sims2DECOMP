// 0x800AF8D8 cBoxX::CheckForTooManySounds(void) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); lwz 9,-24136(13); addi 8,1,32; li 10,0; lwz 11,0x8(9); lwz 0,0x0(11); stw 11,0x20(1); b 1f; 0:; lwz 0,0x0(9); addi 10,10,1; 1:; stw 0,0x24(1); lwz 9,0x24(1); li 11,1; lwz 0,0x0(8); cmpw 9,0; bne 2f; li 11,0; 2:; cmpwi 11,0; bne 0b; cmpwi 10,23; ble 7f; lwz 11,-24136(13); li 29,0; li 30,1024; addi 11,11,4; lwz 0,0x4(11); stw 0,0x10(1); lwz 9,0x4(11); lwz 0,0x0(9); stw 0,0x8(1); stw 0,0x18(1); b 5f; 3:; lwz 9,-24136(13); lwz 31,0x8(3); lwz 3,0x50(9); mr 4,31; bl _s800AF8D8_0; cmpwi 3,0; beq 4f; mr 3,31; bl _s800AF8D8_1; cmpwi 3,2; beq 4f; mr 3,31; bl _s800AF8D8_2; cmpw 3,30; bge 4f; mr 30,3; mr 29,31; 4:; lwz 9,0x8(1); lwz 0,0x0(9); stw 0,0x8(1); 5:; lwz 3,0x8(1); li 9,1; lwz 0,0x10(1); cmpw 3,0; bne 6f; li 9,0; 6:; cmpwi 9,0; bne 3b; cmpwi 29,0; beq 7f; mr 3,29; bl _s800AF8D8_3; 7:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s800AF8D8_0();
extern "C" void _s800AF8D8_1();
extern "C" void _s800AF8D8_2();
extern "C" void _s800AF8D8_3();
extern "C" void f_800AF8D8() {}
