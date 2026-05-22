// 0x80304B10 EController::UpdateStickData(int, (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x1fc(3); rlwinm 5,5,2,0,29; rlwinm 4,4,3,0,28; addi 11,9,40; add 5,5,4; addi 9,9,56; lfsx f0,11,5; lfsx f12,9,5; fsubs f13,f1,f12; fsubs f0,f0,f12; fabs f0,f0; fabs f13,f13; fcmpu 0,f0,f13; bge 0f; stfsx f1,11,5; lwz 9,0x1fc(3); addi 11,9,56; lfsx f0,11,5; addi 9,9,72; fsubs f0,f1,f0; stfsx f0,9,5; 0:; lwz 3,0x1fc(3); lis 9,-32702; lfs f13,-1636(9); addi 11,3,56; lfsx f0,11,5; fmuls f0,f0,f1; fcmpu 0,f0,f13; cror 3,2,0; bnslr; addi 9,3,104; li 0,1; stwx 0,9,5"
extern "C" void f_80304B10() {}
