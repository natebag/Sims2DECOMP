// 0x8021C344 InteractorModule::PlacementObject::ResetDirection(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 4,0x0(3); cmpwi 4,0; beq 0f; li 0,1; lha 3,0x10(3); stw 0,-32044(13); bl _s8021C344_0; li 0,0; stw 0,-32044(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8021C344_0();
extern "C" void f_8021C344() {}
