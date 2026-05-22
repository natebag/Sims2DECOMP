// 0x802A26B0 AptMath::ClipStackInit(unsigned (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mulli 4,31,96; lwz 3,-23020(13); ori 4,4,16; bl _s802A26B0_0; mr 9,3; stw 3,-27248(13); andi. 0,9,15; beq 0f; addi 9,9,16; rlwinm 9,9,0,0,27; 0:; li 0,0; stw 9,-27252(13); sth 31,-27244(13); sth 0,-27242(13); bl _s802A26B0_1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802A26B0_0();
extern "C" void _s802A26B0_1();
extern "C" void f_802A26B0() {}
