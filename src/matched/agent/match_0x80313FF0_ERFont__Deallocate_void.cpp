// 0x80313FF0 ERFont::Deallocate(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 31,0x18(3); cmpwi 31,0; beq 1f; 0:; lwz 3,0x0(31); bl _s80313FF0_0; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80313FF0_0();
extern "C" void f_80313FF0() {}
