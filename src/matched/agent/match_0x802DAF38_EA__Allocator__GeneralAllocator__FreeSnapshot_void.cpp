// 0x802DAF38 EA::Allocator::GeneralAllocator::FreeSnapshot(void (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 0,21326; lwz 9,0x0(4); ori 0,0,16720; cmpw 9,0; bne 0f; lwz 0,0xc(4); cmpwi 0,0; bne 0f; bl _s802DAF38_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802DAF38_0();
extern "C" void f_802DAF38() {}
