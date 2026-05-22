// 0x8025639C SetExiInterruptMask (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; lis 4,-32694; addi 4,4,-22064; addi 4,4,128; cmpwi 3,1; beq 5f; bge 0f; cmpwi 3,0; bge 1f; b 11f; 0:; cmpwi 3,3; bge 11f; b 8f; 1:; lwz 0,0x0(31); cmplwi 0,0; bne 2f; lwz 0,0x0(4); cmplwi 0,0; beq 3f; 2:; lwz 0,0xc(31); rlwinm. 0,0,0,27,27; beq 4f; 3:; lis 3,65; bl _s8025639C_0; b 11f; 4:; lis 3,65; bl _s8025639C_1; b 11f; 5:; lwz 0,0x0(31); cmplwi 0,0; beq 6f; lwz 0,0xc(31); rlwinm. 0,0,0,27,27; beq 7f; 6:; lis 3,8; bl _s8025639C_2; b 11f; 7:; lis 3,8; bl _s8025639C_3; b 11f; 8:; li 3,25; bl _s8025639C_4; cmplwi 3,0; beq 9f; lwz 0,0xc(31); rlwinm. 0,0,0,27,27; beq 10f; 9:; li 3,64; bl _s8025639C_5; b 11f; 10:; li 3,64; bl _s8025639C_6; 11:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025639C_0();
extern "C" void _s8025639C_1();
extern "C" void _s8025639C_2();
extern "C" void _s8025639C_3();
extern "C" void _s8025639C_4();
extern "C" void _s8025639C_5();
extern "C" void _s8025639C_6();
extern "C" void f_8025639C() {}
