// 0x803C22B4 AllocPoolManager<ProtectedAllocPool>::Validate(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); addi 31,3,8; li 30,8; 0:; mr 3,31; bl _s803C22B4_0; addi 31,31,52; addic. 30,30,-1; bne 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803C22B4_0();
extern "C" void f_803C22B4() {}
