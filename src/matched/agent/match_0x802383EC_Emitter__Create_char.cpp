// 0x802383EC Emitter::Create(char (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; addi 3,30,124; bl _s802383EC_0; lis 11,-32704; addi 10,1,8; lfs f0,-2272(11); lis 9,-32704; lfs f13,-2276(9); li 11,0; stfs f0,0x8(10); addi 7,30,128; stfs f0,0x4(10); cmpwi 3,0; stfs f0,0x8(1); li 3,0; stfs f13,0x64(30); lwz 0,0x8(1); lwz 9,0x8(10); lwz 8,0x4(10); stw 0,0x80(30); stw 11,0x70(30); stfs f13,0x60(30); stw 11,0x68(30); stw 11,0x6c(30); stw 9,0x8(7); stw 8,0x4(7); bge 0f; li 3,-1; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s802383EC_0();
extern "C" void f_802383EC() {}
