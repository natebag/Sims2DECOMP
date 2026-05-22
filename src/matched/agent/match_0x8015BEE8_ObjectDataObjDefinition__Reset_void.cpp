// 0x8015BEE8 ObjectDataObjDefinition::Reset(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lbz 0,0x1a(31); cmpwi 0,0; beq 0f; lwz 3,0x1c(31); bl _s8015BEE8_0; li 0,0; stb 0,0x1a(31); stw 0,0x1c(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8015BEE8_0();
extern "C" void f_8015BEE8() {}
