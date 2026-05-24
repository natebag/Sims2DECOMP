// 0x80037D20 EyeToyClient::CompositeFF_callback(ETexture (1024 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-216(1); mfspr 0,8; stmw 27,0xc4(1); stw 0,0xdc(1); lwz 0,-25092(13); mr 31,3; cmpwi 0,0; bne 0f; xoris 0,0,32768; stw 0,0xbc(1); lis 11,17200; lis 10,-32707; li 0,1; stw 11,0xb8(1); addi 8,13,-25100; lfd f13,0x1650(10); lfd f0,0xb8(1); stw 0,-25092(13); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x4(8); stfs f0,0x0(8); 0:; lwz 0,-25080(13); cmpwi 0,0; bne 1f; li 7,1; xoris 0,7,32768; lis 8,17200; stw 0,0xbc(1); lis 9,-32707; lfd f13,0x1650(9); addi 10,13,-25088; stw 8,0xb8(1); stw 7,-25080(13); lfd f0,0xb8(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x4(10); stfs f0,0x0(10); 1:; lwz 0,-25076(13); cmpwi 0,0; bne 2f; lis 11,-32707; lis 10,-32697; lfs f0,0x1658(11); addi 9,10,22144; li 0,1; stfs f0,0xc(9); stfs f0,0x5680(10); stw 0,-25076(13); stfs f0,0x4(9); stfs f0,0x8(9); 2:; lwz 0,-32532(13); cmpwi 0,0; beq 4f; lhz 4,0x12(31); li 5,16; lhz 3,0x10(31); bl _s80037D20_0; mr 27,3; lhz 4,0x12(31); lhz 3,0x10(31); li 5,16; bl _s80037D20_1; mr 28,3; addi 3,1,8; bl _s80037D20_2; addi 3,1,8; li 5,5; mr 4,28; bl _s80037D20_3; lwz 11,-26392(13); li 4,0; lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; addi 3,1,8; mr 4,30; bl _s80037D20_4; lwz 9,0x70(30); li 4,1; li 5,0; lwz 0,0x204(9); lha 3,0x200(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 7,0; li 4,0; li 5,2; lwz 0,0x1cc(9); li 6,0; lha 3,0x1c8(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x70(30); lis 9,-32707; lfs f1,0x165c(9); li 6,0; lwz 0,0x1d4(11); li 5,5; lha 3,0x1d0(11); li 4,0; mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,0; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); mr 4,31; li 5,0; lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,16; li 5,0; lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); lis 11,-32707; addi 4,13,-25100; addi 5,13,-25088; lha 3,0x188(9); lis 8,-32697; lwz 0,0x18c(9); addi 8,8,22144; add 3,30,3; lfs f1,0x1658(11); mr 6,4; mr 7,5; mtspr 8,0; blrl; lwz 9,-32532(13); lwz 3,0x14(9); cmpwi 3,0; bne 3f; lwz 9,0x18(9); li 3,0; cmpwi 9,0; beq 3f; lwz 3,0x14(9); 3:; li 4,0; bl _s80037D20_5; lwz 9,0x70(30); mr 4,3; li 5,0; addi 29,1,168; lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,80; li 5,0; lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x70(30); lis 9,-32707; lfs f1,0x1660(9); li 8,0; lwz 0,0x21c(11); li 4,0; lha 3,0x218(11); li 5,1; mtspr 8,0; li 6,0; add 3,30,3; li 7,1; blrl; lwz 11,0x70(30); addi 7,13,-25088; addi 6,13,-25100; lis 9,-32707; lwz 0,0x18c(11); lis 8,-32697; lha 3,0x188(11); mr 5,7; lfs f1,0x1658(9); addi 8,8,22144; mr 4,6; add 3,30,3; mtspr 8,0; blrl; lwz 11,-26392(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x20(28); mr 4,27; lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0x24(27); li 4,0; mr 5,29; mr 6,29; lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,27,3; blrl; lwz 9,0x24(31); mr 30,3; mr 5,29; li 4,0; lwz 0,0x44(9); mr 6,5; lha 3,0x40(9); mtspr 8,0; add 3,31,3; blrl; lhz 0,0x12(31); mr 4,30; lhz 5,0x10(31); mullw 5,5,0; rlwinm 5,5,1,0,30; bl _s80037D20_6; mr 3,28; bl _s80037D20_7; mr 3,27; bl _s80037D20_8; addi 3,1,8; li 4,2; bl _s80037D20_9; 4:; lwz 0,0xdc(1); mtspr 8,0; lmw 27,0xc4(1); addi 1,1,216"

extern "C" void _s80037D20_0();
extern "C" void _s80037D20_1();
extern "C" void _s80037D20_2();
extern "C" void _s80037D20_3();
extern "C" void _s80037D20_4();
extern "C" void _s80037D20_5();
extern "C" void _s80037D20_6();
extern "C" void _s80037D20_7();
extern "C" void _s80037D20_8();
extern "C" void _s80037D20_9();

struct EyeToyClient {
    void CompositeFF_callback_ETexture();
};

void EyeToyClient::CompositeFF_callback_ETexture() {
}
