// 0x8038B05C GXWaitDrawDone (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s8038B05C_0; mr 31,3; b 1f; 0:; addi 3,13,-21916; bl _s8038B05C_1; 1:; lbz 0,-21920(13); cmplwi 0,0; beq 0b; mr 3,31; bl _s8038B05C_2; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8038B05C_0();
extern "C" void _s8038B05C_1();
extern "C" void _s8038B05C_2();
extern "C" void f_8038B05C() {}
