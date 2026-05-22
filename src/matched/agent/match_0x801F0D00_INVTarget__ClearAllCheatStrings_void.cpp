// 0x801F0D00 INVTarget::ClearAllCheatStrings(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); addi 31,3,395; li 30,5; 0:; mr 3,31; li 4,0; li 5,2048; addi 31,31,2048; bl _s801F0D00_0; addic. 30,30,-1; bne 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F0D00_0();
extern "C" void f_801F0D00() {}
