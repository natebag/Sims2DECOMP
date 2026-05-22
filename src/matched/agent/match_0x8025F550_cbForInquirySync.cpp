// 0x8025F550 cbForInquirySync (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; addi 3,13,-23488; stw 0,0x4(1); stwu 1,-8(1); bl _s8025F550_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025F550_0();
extern "C" void f_8025F550() {}
