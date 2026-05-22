// 0x8002EA64 EIWallPart::DoFadeCollisonForList(TrapezoidFade (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x0(4); mr 30,3; cmpwi 31,0; beq 1f; 0:; lwz 4,0x0(31); mr 3,30; addi 5,4,20; addi 4,4,8; bl _s8002EA64_0; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8002EA64_0();
extern "C" void f_8002EA64() {}
