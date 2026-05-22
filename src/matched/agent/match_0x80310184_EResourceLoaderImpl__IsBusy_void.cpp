// 0x80310184 EResourceLoaderImpl::IsBusy(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 0,0x3e8(31); cmpwi 0,0; bne 0f; addi 3,31,888; bl _s80310184_0; cmpwi 3,0; bne 1f; 0:; lwz 0,0x3e4(31); cmpwi 0,0; beq 2f; 1:; li 30,1; 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80310184_0();
extern "C" void f_80310184() {}
