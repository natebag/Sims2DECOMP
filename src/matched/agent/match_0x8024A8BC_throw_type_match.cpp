// 0x8024A8BC __throw_type_match (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,5; bl _s8024A8BC_0; cmpwi 3,0; mr 3,30; beq 0f; li 3,0; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8024A8BC_0();
extern "C" void f_8024A8BC() {}
