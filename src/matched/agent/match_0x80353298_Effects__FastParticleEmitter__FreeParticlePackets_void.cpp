// 0x80353298 Effects::FastParticleEmitter::FreeParticlePackets(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x19c(31); cmpwi 0,0; beq 3f; lha 0,0x164(31); li 10,0; cmpw 10,0; bge 2f; lis 8,17733; lwz 11,-25872(13); ori 8,8,21062; li 7,0; 0:; lwz 9,0x19c(31); lwzx 9,7,9; cmpwi 9,0; beq 1f; stw 8,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); stw 9,0x4(11); 1:; lha 0,0x164(31); addi 10,10,1; addi 7,7,4; cmpw 10,0; blt 0b; 2:; bl _s80353298_0; lwz 4,0x19c(31); bl _s80353298_1; li 0,0; stw 0,0x19c(31); 3:; li 0,0; sth 0,0x19a(31); sth 0,0x164(31); sth 0,0x198(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80353298_0();
extern "C" void _s80353298_1();
extern "C" void f_80353298() {}
