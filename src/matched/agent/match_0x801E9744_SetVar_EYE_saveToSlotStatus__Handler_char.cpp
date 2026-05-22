// 0x801E9744 SetVar_EYE_saveToSlotStatus::Handler(char (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lbz 0,0x0(4); cmpwi 0,48; bne 0f; lwz 9,-28712(13); lwz 0,0xb4(9); cmpwi 0,0; beq 0f; lwz 3,0x8c(9); bl _s801E9744_0; mr 30,3; addi 5,1,8; lwz 9,0x24(30); mr 6,5; li 4,0; lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,30,3; blrl; lhz 0,0x12(30); lhz 5,0x10(30); lwz 9,-28712(13); mullw 5,5,0; lwz 4,0xb4(9); rlwinm 5,5,1,0,30; bl _s801E9744_1; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s801E9744_0();
extern "C" void _s801E9744_1();
extern "C" void f_801E9744() {}
