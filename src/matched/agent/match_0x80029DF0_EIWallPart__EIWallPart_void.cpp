// 0x80029DF0 EIWallPart::EIWallPart(void) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80029DF0_0; lis 9,-32698; addi 3,31,808; addi 9,9,-20160; stw 9,0x0(31); bl _s80029DF0_1; li 0,0; lis 9,-32707; sth 0,0x358(31); lis 11,-32765; lfs f0,0xd34(9); li 4,5; lha 8,0x358(31); li 10,255; li 9,1; addi 11,11,-25564; mtspr 9,4; stw 9,0x10(31); stw 10,0x330(31); li 6,0; stw 0,0x3ac(31); addi 5,31,840; stfs f0,0x374(31); li 7,0; stw 8,0x28(31); addi 9,31,820; stw 11,0x1c(31); stw 10,0x32c(31); stw 0,0x324(31); stw 0,0x320(31); stw 0,0x3a0(31); stw 0,0x350(31); sth 0,0x35a(31); stfs f0,0x360(31); stfs f0,0x35c(31); stfs f0,0x368(31); stfs f0,0x364(31); stfs f0,0x370(31); stfs f0,0x36c(31); stfs f0,0x378(31); 0:; stw 6,0x0(9); stbx 6,5,7; addi 9,9,4; addi 7,7,1; bdnz 0b; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80029DF0_0();
extern "C" void _s80029DF0_1();
extern "C" void f_80029DF0() {}
