// 0x80311310 EResourceLoaderImpl::GetUnreferencedResourceCount(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x348(3); li 30,0; cmpwi 31,0; beq 1f; 0:; mr 3,31; bl _s80311310_0; lwz 31,0xd04(31); add 30,30,3; cmpwi 31,0; bne 0b; 1:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80311310_0();
extern "C" void f_80311310() {}
