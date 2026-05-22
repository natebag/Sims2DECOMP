// 0x80134C44 RelMatrixImpl::RemoveArray(int) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); addi 9,3,4; lwz 30,0x4(3); lwz 0,0x4(9); cmpw 30,0; beq 8f; 0:; lwz 31,0x0(30); lwz 0,0x10(31); cmpw 0,4; bne 7f; addi 28,3,4; cmpwi 31,0; addi 29,30,4; beq 5f; lwz 9,0x0(31); lwz 0,0x4(31); mr 3,9; cmpw 9,0; beq 2f; 1:; addi 9,9,4; cmpw 9,0; bne 1b; 2:; cmpwi 3,0; beq 4f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 3f; bl _s80134C44_0; b 4f; 3:; bl _s80134C44_1; 4:; mr 3,31; bl _s80134C44_2; 5:; lwz 5,0x4(28); cmpw 29,5; beq 6f; cmpw 5,29; beq 6f; mr 4,29; mr 3,30; subf 5,4,5; bl _s80134C44_3; 6:; lwz 9,0x4(28); addi 9,9,-4; stw 9,0x4(28); b 8f; 7:; lwz 0,0x4(9); addi 30,30,4; cmpw 30,0; bne 0b; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80134C44_0();
extern "C" void _s80134C44_1();
extern "C" void _s80134C44_2();
extern "C" void _s80134C44_3();
extern "C" void f_80134C44() {}
