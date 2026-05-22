// 0x80309388 PyramidFade::PyramidFade(void) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stfd f31,0x60(1); stw 31,0x5c(1); stw 0,0x6c(1); lis 9,-32702; mr 31,3; lfs f31,-1196(9); addi 4,1,8; addi 3,31,8; stfs f31,0x14(1); stfs f31,0x10(1); stfs f31,0xc(1); stfs f31,0x8(1); bl _s80309388_0; addi 4,1,24; stfs f31,0x24(1); stfs f31,0x20(1); addi 3,31,32; stfs f31,0x1c(1); stfs f31,0x18(1); bl _s80309388_1; addi 4,1,40; stfs f31,0x34(1); stfs f31,0x30(1); addi 3,31,56; stfs f31,0x2c(1); stfs f31,0x28(1); bl _s80309388_2; addi 4,1,56; addi 3,31,80; stfs f31,0x44(1); stfs f31,0x40(1); stfs f31,0x3c(1); stfs f31,0x38(1); bl _s80309388_3; stfs f31,0x48(1); addi 3,31,104; stfs f31,0x54(1); addi 4,1,72; stfs f31,0x50(1); stfs f31,0x4c(1); bl _s80309388_4; li 9,1; li 0,0; stw 9,0xa0(31); li 8,0; stw 0,0xac(31); mr 10,31; stw 9,0x9c(31); addi 11,31,4; 0:; stw 8,0x0(11); addi 11,11,-4; cmpw 11,10; bge 0b; mr 3,31; lwz 0,0x6c(1); mtspr 8,0; lwz 31,0x5c(1); lfd f31,0x60(1); addi 1,1,104"
extern "C" void _s80309388_0();
extern "C" void _s80309388_1();
extern "C" void _s80309388_2();
extern "C" void _s80309388_3();
extern "C" void _s80309388_4();
extern "C" void f_80309388() {}
