// 0x80036F64 ESpriteRenderMan::Update(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 31,0x0(30); cmpwi 31,0; beq 1f; 0:; lwz 3,0x0(31); bl _s80036F64_0; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 1:; mr 3,30; bl _s80036F64_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80036F64_0();
extern "C" void _s80036F64_1();
extern "C" void f_80036F64() {}
