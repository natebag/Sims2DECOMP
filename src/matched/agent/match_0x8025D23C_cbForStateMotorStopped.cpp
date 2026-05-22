// 0x8025D23C cbForStateMotorStopped (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-13312; stw 0,0x4(1); li 0,0; lis 4,-32694; stwu 1,-24(1); stw 31,0x14(1); addi 31,4,-17248; stw 0,0x6004(3); li 0,3; lwz 3,-23480(13); stw 0,0xc(3); lwz 0,-23452(13); cmpwi 0,13; beq 1f; bge 0f; cmpwi 0,6; bge 3f; cmpwi 0,4; bge 1f; b 3f; 0:; cmpwi 0,15; beq 1f; b 3f; 1:; bl _s8025D23C_0; lwz 4,-23480(13); addi 0,31,64; stw 0,-23480(13); lwz 12,0x28(4); cmplwi 12,0; beq 2f; mtspr 8,12; li 3,-4; blrl; 2:; bl _s8025D23C_1; b 4f; 3:; li 0,0; stw 0,-23408(13); bl _s8025D23C_2; addi 3,31,112; bl _s8025D23C_3; lis 3,-32768; lwz 0,0xf8(3); lis 4,4194; lis 3,-32730; rlwinm 0,0,30,2,31; addi 4,4,19923; mulhwu 0,4,0; rlwinm 0,0,26,6,31; mulli 6,0,1150; addi 7,3,-12184; addi 3,31,112; li 5,0; bl _s8025D23C_4; 4:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025D23C_0();
extern "C" void _s8025D23C_1();
extern "C" void _s8025D23C_2();
extern "C" void _s8025D23C_3();
extern "C" void _s8025D23C_4();
extern "C" void f_8025D23C() {}
