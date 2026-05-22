// 0x8016FF08 CasSimRendererDynamic::Update(float) (588 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 29,3; lwz 10,0x0(29); cmpwi 10,0; beq 12f; lwz 31,0x1c(10); cmpwi 31,0; beq 12f; lwz 11,0x214(29); mr 0,11; cmpwi 11,0; bge 0f; addi 0,11,3; 0:; rlwinm 0,0,0,0,29; lwz 9,0x1348(31); subf 0,0,11; srw 9,9,0; andi. 0,9,1; beq 12f; lwz 0,0x18(10); cmpwi 0,0; beq 12f; mr 3,31; bl _s8016FF08_0; cmpwi 3,0; beq 1f; li 4,2; b 3f; 1:; mr 3,31; bl _s8016FF08_1; cmpwi 3,0; beq 2f; li 4,0; b 3f; 2:; lwz 9,0x214(29); addi 4,9,3; 3:; lwz 10,0x0(29); addi 5,29,492; addi 6,29,520; lwz 11,0x18(10); lwz 9,0x4(11); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x21c(29); cmpwi 0,0; bne 10f; lwz 3,0x0(29); li 28,0; lwz 31,0x28(3); mr 4,31; bl _s8016FF08_2; mr 27,3; mr 4,31; lwz 3,-26524(13); bl _s8016FF08_3; cmpwi 3,0; beq 4f; lwz 30,-26524(13); mr 4,31; mr 3,30; bl _s8016FF08_4; mr 4,3; mr 3,30; b 5f; 4:; lwz 3,-26524(13); bl _s8016FF08_5; mr 30,3; cmpwi 30,-1; beq 6f; lwz 3,-26524(13); li 4,0; bl _s8016FF08_6; cmpw 30,3; beq 6f; lwz 3,-26524(13); mr 4,30; 5:; bl _s8016FF08_7; mr 28,3; 6:; lis 31,-32706; cmpwi 28,0; lfs f1,0x19fc(31); beq 7f; mr 3,28; mr 6,27; li 4,1; li 5,0; bl _s8016FF08_8; 7:; lfs f9,0x19fc(31); fcmpu 0,f1,f9; beq 10f; lis 9,-32706; fadds f13,f1,f1; lfs f12,0x1a00(9); lis 11,-32706; lfs f11,0x1a04(11); lis 9,-32706; fmuls f13,f13,f12; lfs f0,0x20c(29); lfs f12,-26800(13); lfs f10,0x1a08(9); fmuls f0,f0,f11; fmadds f1,f13,f12,f0; fcmpu 0,f1,f10; ble 8f; fsubs f1,f1,f10; b 9f; 8:; fcmpu 0,f1,f9; bge 9f; fadds f1,f1,f10; 9:; lis 9,-32706; lfs f0,0x1a0c(9); fmuls f0,f1,f0; stfs f0,0x20c(29); 10:; mr 3,29; bl _s8016FF08_9; cmpwi 3,0; bne 12f; addi 31,29,372; lis 4,1; mr 3,31; bl _s8016FF08_10; cmpwi 3,0; beq 11f; mr 3,29; bl _s8016FF08_11; 11:; lis 9,-32706; addi 11,1,8; lfs f0,0x1a10(9); mr 3,31; mr 6,11; li 4,0; stfs f0,0x8(11); li 5,0; stfs f0,0x4(11); stfs f0,0x8(1); bl _s8016FF08_12; 12:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s8016FF08_0();
extern "C" void _s8016FF08_1();
extern "C" void _s8016FF08_2();
extern "C" void _s8016FF08_3();
extern "C" void _s8016FF08_4();
extern "C" void _s8016FF08_5();
extern "C" void _s8016FF08_6();
extern "C" void _s8016FF08_7();
extern "C" void _s8016FF08_8();
extern "C" void _s8016FF08_9();
extern "C" void _s8016FF08_10();
extern "C" void _s8016FF08_11();
extern "C" void _s8016FF08_12();
extern "C" void f_8016FF08() {}
