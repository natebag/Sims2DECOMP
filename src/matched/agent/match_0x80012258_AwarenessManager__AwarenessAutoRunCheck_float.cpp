// 0x80012258 AwarenessManager::AwarenessAutoRunCheck(float) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); fmr f0,f1; li 3,0; andi. 9,0,1; beq 0f; lis 9,-32707; lfs f1,-9084(9); fcmpu 0,f0,f1; cror 3,2,1; bnslr; li 3,1; blr; 0:; lwz 0,-32696(13); cmpwi 0,1; bnelr; lis 9,-32707; lfs f1,-9080(9); fcmpu 0,f0,f1; cror 3,2,1; bnslr; li 3,1"
extern "C" float f_80012258() {}
