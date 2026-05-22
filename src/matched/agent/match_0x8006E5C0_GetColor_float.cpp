// 0x8006E5C0 GetColor(float, (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32707; lfs f0,0x516c(9); fcmpu 0,f1,f0; cror 3,2,0; bsolr; ble 0f; lis 9,-32707; lfs f0,0x5170(9); fcmpu 0,f1,f0; cror 3,2,0; bns 0f; lis 3,-32697; addi 3,3,25280; blr; 0:; lis 9,-32707; lfs f0,0x5170(9); fcmpu 0,f1,f0; ble 1f; lis 9,-32707; lfs f0,0x5174(9); fcmpu 0,f1,f0; cror 3,2,0; bns 1f; lis 3,-32697; addi 3,3,25248; blr; 1:; lis 3,-32697; addi 3,3,25296"
extern "C" float f_8006E5C0() {}
