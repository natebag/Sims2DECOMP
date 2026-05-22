// 0x801D9330 PRGTarget::FormatPercentage(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,4; cmpw 5,6; ble 0f; mr 5,6; 0:; mulli 5,5,100; lis 4,-32705; addi 4,4,19408; addi 3,1,8; divw 5,5,6; crxor 6,6,6; bl _s801D9330_0; addi 3,1,8; bl _s801D9330_1; addi 4,3,1; mr 5,31; addi 3,1,8; bl _s801D9330_2; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s801D9330_0();
extern "C" void _s801D9330_1();
extern "C" void _s801D9330_2();
extern "C" void f_801D9330() {}
