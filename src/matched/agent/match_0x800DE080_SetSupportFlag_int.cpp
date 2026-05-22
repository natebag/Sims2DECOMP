// 0x800DE080 SetSupportFlag(int, (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 0,4; mr 31,6; mr 6,5; mr 4,3; mr 5,0; addi 3,1,8; bl _s800DE080_0; lwz 11,-21488(13); addi 4,1,8; lwz 9,0x0(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 3,-21488(13); addi 4,1,8; lwz 9,0x0(3); lha 0,0xf8(9); lwz 9,0xfc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 7,31,0; andi. 5,3,247; beq cr7,0f; ori 5,5,8; 0:; lwz 3,-21488(13); addi 4,1,8; lwz 9,0x0(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; 1:; addi 3,1,8; li 4,2; bl _s800DE080_1; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s800DE080_0();
extern "C" void _s800DE080_1();
extern "C" void f_800DE080() {}
