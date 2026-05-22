// 0x8035C698 EMsgQueue::Destroy(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; stw 30,0x38(31); bl _s8035C698_0; addi 3,31,24; bl _s8035C698_1; lwz 0,0x40(31); cmpwi 0,0; beq 0f; bl _s8035C698_2; lwz 4,0x3c(31); bl _s8035C698_3; stw 30,0x40(31); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035C698_0();
extern "C" void _s8035C698_1();
extern "C" void _s8035C698_2();
extern "C" void _s8035C698_3();
extern "C" void f_8035C698() {}
