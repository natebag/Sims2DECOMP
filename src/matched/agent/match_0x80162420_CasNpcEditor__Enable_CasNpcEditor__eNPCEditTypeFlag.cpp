// 0x80162420 CasNpcEditor::Enable(CasNpcEditor::eNPCEditTypeFlag) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 29,0xc(1); stw 0,0x1c(1); stw 12,0x8(1); mr 29,4; mr 31,3; cmpwi 4,29,3; bgt cr4,3f; lis 30,-32706; stw 29,0x8(31); addi 4,30,-2656; addi 3,31,92; bl _s80162420_0; addi 4,30,-2656; addi 3,31,96; bl _s80162420_1; addi 4,30,-2656; addi 3,31,100; bl _s80162420_2; cmpwi 29,2; beq 0f; beq cr4,2f; b 4f; 0:; lwz 0,0x58(31); cmpwi 0,0; bne 1f; lwz 10,0x0(31); li 4,0; lwz 9,0x1c(10); lwz 11,0x1370(9); lwz 0,0x94(11); mr 3,0; stw 0,0x58(31); bl _s80162420_3; 1:; li 0,52; stw 0,0x10(31); b 4f; 2:; li 0,162; stw 0,0x10(31); b 4f; 3:; li 0,0; stw 0,0x8(31); 4:; lwz 0,0x1c(1); lwz 12,0x8(1); mtspr 8,0; lmw 29,0xc(1); mtcrf 8,12; addi 1,1,24"
extern "C" void _s80162420_0();
extern "C" void _s80162420_1();
extern "C" void _s80162420_2();
extern "C" void _s80162420_3();
extern "C" void f_80162420() {}
