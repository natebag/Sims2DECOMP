// 0x802C6AA4 EFileSystem::FileCreator::FileCreator(EFile (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; stw 4,0x0(31); mr. 4,8; stw 5,0x4(31); stw 6,0x8(31); stw 7,0xc(31); stb 30,0x10(31); stb 30,0x11(31); stb 30,0x12(31); stb 30,0x13(31); beq 1f; lbz 0,0x0(4); cmpwi 0,46; bne 0f; addi 4,4,1; 0:; addi 3,31,16; li 5,3; bl _s802C6AA4_0; stb 30,0x13(31); 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C6AA4_0();
extern "C" void f_802C6AA4() {}
