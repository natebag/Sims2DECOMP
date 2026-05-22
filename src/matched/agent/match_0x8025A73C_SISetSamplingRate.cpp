// 0x8025A73C SISetSamplingRate (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); addi 29,3,0; cmplwi 29,11; lis 3,-32700; addi 31,3,-15760; ble 0f; li 29,11; 0:; bl _s8025A73C_0; stw 29,-23528(13); mr 30,3; bl _s8025A73C_1; cmpwi 3,2; beq 2f; bge 1f; cmpwi 3,0; beq 2f; bge 3f; b 4f; 1:; cmpwi 3,5; beq 2f; b 4f; 2:; mr 4,31; b 5f; 3:; addi 4,31,48; b 5f; 4:; addi 3,31,96; crxor 6,6,6; bl _s8025A73C_2; li 29,0; addi 4,31,0; 5:; lis 3,-13312; lhz 0,0x206c(3); rlwinm. 0,0,0,31,31; beq 6f; li 5,2; b 7f; 6:; li 5,1; 7:; rlwinm 3,29,2,0,29; lhzx 0,4,3; add 3,4,3; lbz 4,0x2(3); mullw 3,5,0; bl _s8025A73C_3; mr 3,30; bl _s8025A73C_4; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025A73C_0();
extern "C" void _s8025A73C_1();
extern "C" void _s8025A73C_2();
extern "C" void _s8025A73C_3();
extern "C" void _s8025A73C_4();
extern "C" void f_8025A73C() {}
