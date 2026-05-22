// 0x80306978 ilog2(float) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32702; lfs f0,-1392(9); fcmpu 0,f1,f0; bge 0f; fdivs f1,f0,f1; li 3,-1; b 1f; 0:; li 3,1; 1:; lis 9,-32702; lfs f0,-1388(9); li 10,0; li 9,1; fadds f0,f1,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 0,0xc(1); cmplw 9,0; bge 3f; 2:; rlwinm 9,9,1,0,30; addi 10,10,1; cmplw 9,0; blt 2b; 3:; mullw 3,3,10; addi 1,1,16"
extern "C" void f_80306978() {}
