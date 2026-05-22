// 0x802DAB30 EA::Allocator::GeneralAllocator::ReportEnd(void (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 1f; lwz 9,0x0(4); lis 0,21326; ori 0,0,16720; cmpw 9,0; bne 1f; lwz 0,0x10(4); cmpwi 0,0; beq 0f; bl _s802DAB30_0; b 1f; 0:; stw 0,0x28(4); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802DAB30_0();
extern "C" void f_802DAB30() {}
