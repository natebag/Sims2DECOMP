// 0x8004A940 DrawSubModelShader(ERC (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 27,0; li 31,0; b 1f; 0:; addi 31,31,4; addi 27,27,1; 1:; cmpw 27,26; bge 2f; lwzx 3,31,28; cmpwi 3,0; beq 0b; bl _s8004A940_0; cmpw 3,24; bne 0b; lwzx 0,31,28; addi 29,29,1; cmpw 29,25; stw 0,0x0(30); addi 30,30,4; blt 0b; 2:; mr 3,29; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8004A940_1; cmpwi 3,-1; beq 3f; rlwinm 0,3,2,0,29; lwzx 3,31,0; b 4f; 3:; li 3,0; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8004A940_0();
extern "C" void _s8004A940_1();
extern "C" void f_8004A940() {}
