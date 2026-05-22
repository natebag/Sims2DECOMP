// 0x80387078 EnableWriteGatherPipe (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s80387078_0; lis 4,3073; mr 31,3; addi 3,4,-32768; bl _s80387078_1; oris 3,31,16384; bl _s80387078_2; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80387078_0();
extern "C" void _s80387078_1();
extern "C" void _s80387078_2();
extern "C" void f_80387078() {}
