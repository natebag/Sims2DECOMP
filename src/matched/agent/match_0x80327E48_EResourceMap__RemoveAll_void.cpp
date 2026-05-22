// 0x80327E48 EResourceMap::RemoveAll(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; beq 0f; bl _s80327E48_0; lwz 4,0x0(31); bl _s80327E48_1; 0:; li 0,0; stw 0,0x10(31); stw 0,0x0(31); stw 0,0x4(31); stw 0,0x8(31); stw 0,0xc(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80327E48_0();
extern "C" void _s80327E48_1();
extern "C" void f_80327E48() {}
