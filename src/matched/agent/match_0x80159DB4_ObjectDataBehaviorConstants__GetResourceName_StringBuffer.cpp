// 0x80159DB4 ObjectDataBehaviorConstants::GetResourceName(StringBuffer (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 3,4; bl _s80159DB4_0; li 3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80159DB4_0();
extern "C" void f_80159DB4() {}
