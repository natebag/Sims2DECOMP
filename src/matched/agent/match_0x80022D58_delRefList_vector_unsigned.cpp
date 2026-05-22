// 0x80022D58 delRefList(vector<unsigned (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; lwz 9,0x0(29); lwz 0,0x4(29); subf 0,9,0; srawi. 9,0,2; mtspr 9,9; ble 1f; mfspr 31,9; lis 28,-32693; li 30,0; 0:; lwz 9,0x0(29); addi 3,28,24536; li 5,0; lwzx 4,9,30; addi 30,30,4; bl _s80022D58_0; addic. 31,31,-1; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80022D58_0();
extern "C" void f_80022D58() {}
