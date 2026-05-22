// 0x80313298 EResPrefetchFile::SetStreamBuffer(EResourceManager (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 0,0; mr 30,4; stw 0,0x40(31); mr 4,5; stw 6,0x30(31); cmpwi 8,-1; stw 7,0x14(31); stw 0,0x2c(31); stw 0,0x3c(31); stw 6,0x34(31); stw 7,0x38(31); bne 0f; mr 3,30; bl _s80313298_0; stw 3,0x3c(31); b 1f; 0:; stw 8,0x3c(31); 1:; lwz 0,0x3c(31); stw 30,0x2c(31); stw 0,0x40(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80313298_0();
extern "C" void f_80313298() {}
