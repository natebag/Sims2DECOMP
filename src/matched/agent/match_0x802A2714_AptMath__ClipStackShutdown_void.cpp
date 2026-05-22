// 0x802A2714 AptMath::ClipStackShutdown(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-27252(13); cmpwi 0,0; beq 0f; lhz 5,-27244(13); lwz 3,-23020(13); mulli 5,5,96; lwz 4,-27248(13); ori 5,5,16; bl _s802A2714_0; 0:; li 0,0; stw 0,-27252(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802A2714_0();
extern "C" void f_802A2714() {}
