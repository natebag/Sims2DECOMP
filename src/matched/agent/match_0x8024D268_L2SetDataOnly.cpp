// 0x8024D268 L2SetDataOnly (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); cmpwi 3,0; beq 0f; bl _s8024D268_0; oris 3,3,64; bl _s8024D268_1; b 1f; 0:; bl _s8024D268_2; rlwinm 3,3,0,10,8; bl _s8024D268_3; 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024D268_0();
extern "C" void _s8024D268_1();
extern "C" void _s8024D268_2();
extern "C" void _s8024D268_3();
extern "C" void f_8024D268() {}
