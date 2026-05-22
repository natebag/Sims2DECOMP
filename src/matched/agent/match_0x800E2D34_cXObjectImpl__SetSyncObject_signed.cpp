// 0x800E2D34 cXObjectImpl::SetSyncObject(signed (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; li 30,0; addi 5,1,8; addi 6,1,10; sth 30,0xc(1); bl _s800E2D34_0; lha 5,0xa(1); li 7,0; lha 4,0x8(1); addi 8,1,12; li 6,0; mr 3,31; bl _s800E2D34_1; lwz 3,-21484(13); lha 4,0xc(1); lwz 9,0x0(3); lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 0f; lwz 0,0x4(31); cmpw 3,0; bne 1f; 0:; lis 9,-32706; stw 30,0xe4(31); lfs f0,-20720(9); li 3,0; stw 30,0xdc(31); stfs f0,0xe0(31); b 3f; 1:; lwz 0,0xdc(31); cmpw 0,3; beq 2f; lis 9,-32706; li 0,1; lfs f0,-20720(9); stw 0,0xe4(31); stw 3,0xdc(31); stfs f0,0xe0(31); 2:; li 3,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800E2D34_0();
extern "C" void _s800E2D34_1();
extern "C" void f_800E2D34() {}
