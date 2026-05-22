// 0x80135384 RelMatrixImpl::Clear(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; addi 11,29,4; lwz 9,0x4(29); lwz 0,0x4(11); cmpw 9,0; beq 6f; mr 30,11; 0:; lwz 9,0x4(30); lwzu 31,-4(9); stw 9,0x4(30); cmpwi 31,0; beq 5f; lwz 9,0x0(31); lwz 0,0x4(31); mr 3,9; cmpw 9,0; beq 2f; 1:; addi 9,9,4; cmpw 9,0; bne 1b; 2:; cmpwi 3,0; beq 4f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 3f; bl _s80135384_0; b 4f; 3:; bl _s80135384_1; 4:; mr 3,31; bl _s80135384_2; 5:; lwz 9,0x4(29); lwz 0,0x4(30); cmpw 9,0; bne 0b; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80135384_0();
extern "C" void _s80135384_1();
extern "C" void _s80135384_2();
extern "C" void f_80135384() {}
