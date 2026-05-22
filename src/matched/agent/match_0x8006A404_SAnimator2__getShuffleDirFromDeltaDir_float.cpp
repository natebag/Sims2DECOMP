// 0x8006A404 SAnimator2::getShuffleDirFromDeltaDir(float) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32707; lfs f0,0x4ccc(9); fdivs f0,f1,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 3,0xc(1); cmpwi 3,4; beq 3f; cmpwi 3,-4; beq 3f; lis 9,-32707; lfs f0,0x4cd0(9); fcmpu 0,f1,f0; beq 3f; lis 11,-32707; lfs f0,0x4cd4(11); fdivs f0,f1,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 9,0xc(1); cmpwi 9,0; beq 1f; ble 0f; addi 3,3,1; b 1f; 0:; addi 3,3,-1; 1:; lis 9,-32707; lfs f0,0x4cd0(9); fcmpu 0,f1,f0; bge 2f; addi 3,3,1; b 3f; 2:; addi 3,3,-1; 3:; addi 1,1,16"
extern "C" void f_8006A404() {}
