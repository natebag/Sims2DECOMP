// 0x8035B788 EFloatTree::FindKeyOrParent(float) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3); lis 9,-32700; addi 9,9,11784; li 11,0; 0:; cmpw 3,9; beq 2f; lfs f0,0x1c(3); fcmpu 0,f1,f0; beqlr; mr 11,3; bge 1f; lwz 3,0x0(11); b 0b; 1:; lwz 3,0x4(11); b 0b; 2:; mr 3,11"
extern "C" float f_8035B788() {}
