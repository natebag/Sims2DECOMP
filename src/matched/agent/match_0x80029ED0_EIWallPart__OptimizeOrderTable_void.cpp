// 0x80029ED0 EIWallPart::OptimizeOrderTable(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); stmw 26,0x8(1); lwz 9,0x120(3); addi 30,3,820; addi 10,3,840; li 12,0; lwz 29,0x3c(9); mr 27,10; li 9,5; li 0,0; mtspr 9,9; mr 11,30; 0:; stw 0,0x0(11); stbx 0,10,12; addi 11,11,4; addi 12,12,1; bdnz 0b; li 0,5; li 12,0; mtspr 9,0; li 28,0; lis 26,-32702; 1:; lwz 5,0x4(29); li 6,0; cmpw 6,5; bge 4f; addi 31,26,14912; mr 8,28; mr 4,30; mr 3,27; li 7,0; 2:; lwz 0,0x0(29); lwzx 11,31,8; add 10,0,7; lwz 9,0xc(10); cmpw 9,11; bne 3f; lwzx 0,4,8; cmpwi 0,0; bne 5f; stwx 10,30,8; stbx 6,3,12; b 4f; 3:; addi 6,6,1; addi 7,7,112; cmpw 6,5; blt 2b; 4:; addi 28,28,4; addi 12,12,1; bdnz 1b; 5:; lmw 26,0x8(1); addi 1,1,32"
extern "C" void f_80029ED0() {}
