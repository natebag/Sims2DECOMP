// 0x8008CCC0 ChangeHouseDemolishHouse::Update(float) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-32160(13); mr 31,3; lwz 0,0xb4(9); andi. 9,0,4; beq 0f; lis 9,-32697; lwz 10,-21496(13); lwz 11,0x5c48(9); li 0,1; li 4,0; stw 0,0x34(11); lwz 9,0x0(10); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,-21496(13); lwz 9,0x0(11); lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,11,3; blrl; bl _s8008CCC0_0; lwz 11,-21484(13); lwz 9,0x0(11); lha 3,0x68(9); lwz 0,0x6c(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32707; mr 3,31; lfs f1,0x7da8(9); li 4,1; bl _s8008CCC0_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8008CCC0_0();
extern "C" void _s8008CCC0_1();
extern "C" void f_8008CCC0() {}
