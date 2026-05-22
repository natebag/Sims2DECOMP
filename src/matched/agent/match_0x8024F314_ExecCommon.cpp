// 0x8024F314 ExecCommon (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-88(1); stw 31,0x54(1); mr 31,4; lbz 0,0x0(3); extsb 0,0; cmpwi 0,0; bne 0f; li 3,0; b 2f; 0:; addi 4,1,16; bl _s8024F314_0; cmpwi 3,0; beq 1f; lwz 3,0x40(1); b 2f; 1:; b 3f; 2:; mr 5,31; lis 4,-16384; bl _s8024F314_1; 3:; lwz 0,0x5c(1); lwz 31,0x54(1); addi 1,1,88; mtspr 8,0"
extern "C" void _s8024F314_0();
extern "C" void _s8024F314_1();
extern "C" void f_8024F314() {}
