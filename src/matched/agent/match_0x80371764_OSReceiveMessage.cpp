// 0x80371764 OSReceiveMessage (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,3,0; stw 30,0x20(1); addi 30,5,0; stw 29,0x1c(1); stw 28,0x18(1); addi 28,4,0; bl _s80371764_0; addi 29,3,0; rlwinm 30,30,0,31,31; b 2f; 0:; cmpwi 30,0; bne 1f; mr 3,29; bl _s80371764_1; li 3,0; b 4f; 1:; addi 3,31,8; bl _s80371764_2; 2:; lwz 0,0x1c(31); cmpwi 0,0; beq 0b; cmplwi 28,0; beq 3f; lwz 0,0x18(31); lwz 3,0x10(31); rlwinm 0,0,2,0,29; lwzx 0,3,0; stw 0,0x0(28); 3:; lwz 5,0x18(31); mr 3,31; lwz 4,0x14(31); addi 5,5,1; divw 0,5,4; mullw 0,0,4; subf 0,0,5; stw 0,0x18(31); lwz 4,0x1c(31); addi 0,4,-1; stw 0,0x1c(31); bl _s80371764_3; mr 3,29; bl _s80371764_4; li 3,1; 4:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80371764_0();
extern "C" void _s80371764_1();
extern "C" void _s80371764_2();
extern "C" void _s80371764_3();
extern "C" void _s80371764_4();
extern "C" void f_80371764() {}
