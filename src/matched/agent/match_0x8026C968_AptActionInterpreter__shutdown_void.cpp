// 0x8026C968 AptActionInterpreter::shutdown(void) (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lwz 4,0x8(31); cmpwi 4,0; beq 0f; lwz 5,0x4(31); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s8026C968_0; 0:; li 28,0; addi 30,31,12; stw 28,0x4(31); stw 28,0x0(31); stw 28,0x8(31); lwz 4,0x8(30); cmpwi 4,0; beq 1f; lwz 5,0x4(30); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s8026C968_1; 1:; stw 28,0x4(30); addi 29,31,24; stw 28,0xc(31); stw 28,0x8(30); lwz 4,0x8(29); cmpwi 4,0; beq 2f; lwz 5,0x4(29); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s8026C968_2; 2:; stw 28,0x4(29); addi 30,31,36; stw 28,0x18(31); stw 28,0x8(29); lwz 4,0x8(30); cmpwi 4,0; beq 3f; lwz 5,0x4(30); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s8026C968_3; 3:; stw 28,0x4(30); stw 28,0x24(31); stw 28,0x8(30); bl _s8026C968_4; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8026C968_0();
extern "C" void _s8026C968_1();
extern "C" void _s8026C968_2();
extern "C" void _s8026C968_3();
extern "C" void _s8026C968_4();
extern "C" void f_8026C968() {}
