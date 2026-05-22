// 0x8024D1D0 L2GlobalInvalidate (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); sync; bl _s8024D1D0_0; rlwinm 3,3,0,1,31; bl _s8024D1D0_1; sync; bl _s8024D1D0_2; oris 3,3,32; bl _s8024D1D0_3; b 0f; 0:; b 1f; 1:; bl _s8024D1D0_4; rlwinm 0,3,0,31,31; cmplwi 0,0; bne 1b; bl _s8024D1D0_5; rlwinm 3,3,0,11,9; bl _s8024D1D0_6; b 2f; 2:; lis 3,-32700; addi 31,3,-20544; b 3f; 3:; b 5f; 4:; mr 3,31; crxor 6,6,6; bl _s8024D1D0_7; 5:; bl _s8024D1D0_8; rlwinm 0,3,0,31,31; cmplwi 0,0; bne 4b; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8024D1D0_0();
extern "C" void _s8024D1D0_1();
extern "C" void _s8024D1D0_2();
extern "C" void _s8024D1D0_3();
extern "C" void _s8024D1D0_4();
extern "C" void _s8024D1D0_5();
extern "C" void _s8024D1D0_6();
extern "C" void _s8024D1D0_7();
extern "C" void _s8024D1D0_8();
extern "C" void f_8024D1D0() {}
