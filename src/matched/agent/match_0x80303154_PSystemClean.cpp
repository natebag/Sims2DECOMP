// 0x80303154 PSystemClean (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr. 31,3; beq 5f; lwz 9,0x0(31); lwz 0,0x88(9); stw 0,0x90(9); b 2f; 0:; lwz 9,0x0(31); lwz 3,0x8(1); lwz 11,0x90(9); lwz 0,0x0(11); stw 0,0x90(9); bl _s80303154_0; lwz 9,0x8(1); lwz 0,0xa4(9); cmpwi 0,0; beq 1f; lwz 3,0xa8(9); mtspr 8,0; blrl; 1:; lwz 4,0x8(1); mr 3,31; bl _s80303154_1; addi 3,1,8; bl _s80303154_2; 2:; lwz 9,0x0(31); lwz 9,0x90(9); cmpwi 9,0; beq 3f; lwz 0,0x8(9); stw 0,0x8(1); b 4f; 3:; stw 9,0x8(1); 4:; lwz 0,0x8(1); cmpwi 0,0; bne 0b; 5:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s80303154_0();
extern "C" void _s80303154_1();
extern "C" void _s80303154_2();
extern "C" void f_80303154() {}
