// 0x80310D4C EResourceLoaderImpl::FindResourceManagerInternal(char (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x348(3); mr 30,4; cmpwi 31,0; beq 2f; 0:; lwz 3,0x40(31); mr 4,30; bl _s80310D4C_0; cmpwi 3,0; bne 1f; mr 3,31; b 3f; 1:; lwz 31,0xd04(31); cmpwi 31,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80310D4C_0();
extern "C" void f_80310D4C() {}
