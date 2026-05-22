// 0x8004B8E0 EParticleEffect::EParticleEffect(AttachmentNode (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 30,0; li 0,0; stw 30,0x44(31); stw 30,0x48(31); mr 29,4; stw 30,0x4c(31); mr 28,5; sth 0,0x40(31); bl _s8004B8E0_0; stw 30,0x5c(31); li 10,1; stw 30,0x68(31); stw 30,0x6c(31); stw 30,0x58(31); lbz 11,-18452(13); lwz 4,0x4(29); stw 4,0x60(31); lbz 9,0x0(29); lbz 0,-18452(13); andc 0,9,0; extsb 8,0; stw 8,0x64(31); lhz 9,0x2(29); sth 9,0x40(31); lbz 0,0x0(29); extsb 0,0; and. 9,0,11; bne 0f; li 10,0; 0:; stw 10,0x4c(31); cmpwi 8,0; lwz 9,0x0(28); lwz 10,0x4(28); stw 9,0x0(31); stw 10,0x4(31); lwz 11,0x8(28); lwz 12,0xc(28); stw 11,0x8(31); stw 12,0xc(31); lwz 9,0x10(28); lwz 10,0x14(28); stw 9,0x10(31); stw 10,0x14(31); lwz 11,0x18(28); lwz 12,0x1c(28); stw 11,0x18(31); stw 12,0x1c(31); lwz 9,0x20(28); lwz 10,0x24(28); stw 9,0x20(31); stw 10,0x24(31); lwz 11,0x28(28); lwz 12,0x2c(28); stw 11,0x28(31); stw 12,0x2c(31); lwz 9,0x30(28); lwz 10,0x34(28); stw 9,0x30(31); stw 10,0x34(31); lwz 11,0x38(28); lwz 12,0x3c(28); stw 11,0x38(31); stw 12,0x3c(31); bne 1f; lis 3,-32692; addi 3,3,6092; bl _s8004B8E0_1; b 2f; 1:; cmpwi 8,1; bne 2f; lis 3,-32692; addi 3,3,-644; bl _s8004B8E0_2; 2:; mr 3,31; bl _s8004B8E0_3; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8004B8E0_0();
extern "C" void _s8004B8E0_1();
extern "C" void _s8004B8E0_2();
extern "C" void _s8004B8E0_3();
extern "C" void f_8004B8E0() {}
