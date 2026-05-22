// 0x80134D30 RelMatrixImpl::SetArraySize(int, (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 30,4; mr 29,5; addi 28,31,4; bl _s80134D30_0; lwz 0,0x4(28); cmpw 3,0; bne 0f; mr 3,31; mr 4,30; bl _s80134D30_1; mr 3,31; mr 4,30; bl _s80134D30_2; lwz 0,0x4(28); cmpw 3,0; beq 4f; 0:; lwz 10,0x0(3); lwz 9,0x4(10); lwz 0,0x0(10); subf 0,0,9; srawi 0,0,2; cmplw 0,29; bge 1f; li 0,0; mr 3,10; stw 0,0x8(1); addi 6,1,8; lwz 5,0x4(10); lwz 0,0x0(10); mr 4,5; subf 5,0,5; srawi 5,5,2; subf 5,5,29; bl _s80134D30_3; b 4f; 1:; ble 4f; subf 0,29,0; rlwinm 0,0,2,0,29; subf 0,0,9; lwz 11,0x4(10); mr 9,0; cmpw 0,11; beq 3f; 2:; addi 9,9,4; cmpw 9,11; bne 2b; 3:; stw 0,0x4(10); 4:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80134D30_0();
extern "C" void _s80134D30_1();
extern "C" void _s80134D30_2();
extern "C" void _s80134D30_3();
extern "C" void f_80134D30() {}
