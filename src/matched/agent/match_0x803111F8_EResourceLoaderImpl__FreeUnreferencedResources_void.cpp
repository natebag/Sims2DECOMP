// 0x803111F8 EResourceLoaderImpl::FreeUnreferencedResources(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 31,0x348(3); li 29,0; cmpwi 31,0; beq 3f; 0:; mr 3,31; li 30,0; bl _s803111F8_0; cmpwi 3,0; bne 1f; cmpwi 29,0; beq 2f; 1:; li 30,1; 2:; lwz 31,0xd04(31); mr 29,30; cmpwi 31,0; bne 0b; 3:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803111F8_0();
extern "C" void f_803111F8() {}
