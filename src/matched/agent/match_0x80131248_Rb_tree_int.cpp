// 0x80131248 _Rb_tree<int, (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="ble cr4,0f; lwz 11,0x8(3); rlwinm 9,21,0,16,31; lwz 0,0xc(3); subf 0,11,0; srawi 0,0,2; cmplw 9,0; bgt 0f; addi 9,21,-1; rlwinm 9,9,2,0,29; lfsx f1,11,9; b 1f; 0:; lis 9,-32706; lfs f1,-12404(9); 1:; lwz 0,0x9c(1); lwz 12,0x3c(1); mtspr 8,0; lmw 14,0x40(1); lfd f30,0x88(1); lfd f31,0x90(1); mtcrf 24,12; addi 1,1,152"
extern "C" float f_80131248() {}
