// 0x80034090 ESim::Update(void) (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x638(31); cmpwi 0,0; beq 4f; lwz 3,-26824(13); bl _s80034090_0; cmpwi 3,0; beq 4f; lwz 3,0x3d0(31); lwz 9,0x4(3); lha 0,0x160(9); lwz 9,0x164(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lis 9,-32765; addi 9,9,11352; b 1f; 0:; lis 9,-32765; addi 9,9,12084; 1:; stw 9,0x454(31); mr 3,31; bl _s80034090_1; mr 3,31; bl _s80034090_2; mr 3,31; bl _s80034090_3; mr 3,31; bl _s80034090_4; mr 3,31; bl _s80034090_5; cmpwi 3,0; beq 2f; lwz 3,0x3e0(31); cmpwi 3,0; beq 4f; lwz 0,0x5c(3); oris 0,0,16; stw 0,0x5c(3); b 4f; 2:; lwz 11,0x3d0(31); lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; lwz 11,0x3d0(31); li 4,30; lwz 9,0x4(11); lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; bne 3f; lwz 0,0x640(31); cmpwi 0,0; beq 3f; lis 9,-32707; lfs f0,0x11f4(9); stfs f0,0x64(31); stfs f0,0x60(31); 3:; stw 3,0x640(31); mr 3,31; bl _s80034090_6; mr 3,31; bl _s80034090_7; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80034090_0();
extern "C" void _s80034090_1();
extern "C" void _s80034090_2();
extern "C" void _s80034090_3();
extern "C" void _s80034090_4();
extern "C" void _s80034090_5();
extern "C" void _s80034090_6();
extern "C" void _s80034090_7();
extern "C" void f_80034090() {}
