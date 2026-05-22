// 0x8017A8FC UIDrawTable::InstallEntry(UIDrawTable::DrawTablePriority, (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x8(3); cmpwi 0,0; beq 2f; lwz 9,0x0(3); cmpwi 9,0; beq 1f; 0:; lwz 0,0xc(9); cmpw 0,5; beq 2f; lwz 9,0x4(9); cmpwi 9,0; bne 0b; 1:; bl _s8017A8FC_0; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8017A8FC_0();
extern "C" void f_8017A8FC() {}
