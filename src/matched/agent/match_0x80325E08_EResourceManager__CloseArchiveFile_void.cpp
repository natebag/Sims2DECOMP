// 0x80325E08 EResourceManager::CloseArchiveFile(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 4,-1; bl _s80325E08_0; lwz 9,0x50(30); li 0,0; stw 0,0x50(30); mr 3,30; stw 9,0x8(1); bl _s80325E08_1; lwz 0,0x8(1); cmpwi 0,0; beq 0f; lis 3,-32694; addi 4,1,8; addi 3,3,-10620; bl _s80325E08_2; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80325E08_0();
extern "C" void _s80325E08_1();
extern "C" void _s80325E08_2();
extern "C" void f_80325E08() {}
