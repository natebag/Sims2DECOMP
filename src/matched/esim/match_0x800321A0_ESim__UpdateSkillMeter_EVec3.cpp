// 0x800321A0 ESim::UpdateSkillMeter(EVec3 (744 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 31,3; mr 29,5; mr 30,4; bl _s800321A0_0; addi 0,31,968; mr 4,3; mr 3,0; bl _s800321A0_1; mr 28,3; mr 3,31; bl _s800321A0_2; cmpwi 3,0; bne 3f; lfs f0,-32596(13); lfs f8,-26796(13); lfs f12,-32624(13); fadds f0,f0,f8; fadds f13,f12,f12; stfs f0,-32596(13); fcmpu 0,f0,f13; ble 0f; lis 9,-32707; lwz 11,-32592(13); lwz 0,-32588(13); lfs f0,0x1154(9); stw 0,-32592(13); stfs f0,-32596(13); stw 11,-32588(13); 0:; lis 9,-32707; lfs f13,-32596(13); lfs f0,0x1158(9); addi 11,13,-32604; lwz 9,-32592(13); lis 10,-32707; fmuls f13,f13,f0; lwz 0,-32588(13); fdivs f13,f13,f12; rlwinm 9,9,2,0,29; rlwinm 0,0,2,0,29; lfsx f10,9,11; lfsx f12,11,0; lis 9,-32707; lfs f0,-32612(13); lfs f11,0x115c(10); lfs f9,0x1154(9); fsubs f12,f12,f10; fmadds f11,f8,f11,f0; fmadds f13,f13,f12,f10; stfs f11,-32612(13); stfs f13,-32616(13); fcmpu 0,f11,f9; bge 1f; lis 9,-32707; lfs f13,0x1160(9); b 2f; 1:; lis 9,-32707; fmr f13,f11; lfs f0,0x1160(9); fcmpu 0,f11,f0; ble 2f; fmr f13,f9; 2:; stfs f13,-32612(13); 3:; lwz 0,0x3ec(31); lis 9,-32707; lfs f1,0x1164(9); cmplwi 0,5; blt 11f; cmplwi 0,6; ble 4f; cmplwi 0,9; bgt 11f; cmplwi 0,8; blt 11f; b 7f; 4:; lis 9,-32707; lfs f0,0x3f4(31); lfs f13,0x1168(9); fcmpu 0,f0,f13; bge 5f; fdivs f0,f0,f13; fsubs f1,f1,f0; b 11f; 5:; lis 4,27935; mr 3,28; ori 4,4,2390; bl _s800321A0_3; mr 3,28; li 4,0; bl _s800321A0_4; lwz 3,0x3e8(31); cmpwi 3,0; beq 6f; bl _s800321A0_5; li 0,0; stw 0,0x3e8(31); 6:; lis 3,-32692; lis 4,27935; addi 3,3,-27556; ori 4,4,2390; li 5,0; li 6,0; bl _s800321A0_6; lis 9,-32707; li 0,7; lfs f0,0x1154(9); stw 3,0x3e8(31); stw 0,0x3ec(31); fmr f1,f0; stfs f0,0x3f4(31); b 11f; 7:; lis 9,-32707; lfs f11,0x3f4(31); lfs f13,0x116c(9); fcmpu 0,f11,f13; bge 8f; lis 9,-32707; lfs f0,0x1170(9); fmuls f0,f11,f0; fdivs f1,f0,f13; b 11f; 8:; lis 9,-32707; lfs f0,0x1168(9); fcmpu 0,f11,f0; bge 9f; lis 11,-32707; fsubs f11,f11,f13; lfs f0,0x1174(11); lis 9,-32707; lfs f12,0x1164(9); lis 11,-32707; fdivs f1,f11,f0; lfs f13,0x1158(11); fsubs f0,f12,f1; fmadds f1,f0,f13,f12; b 11f; 9:; lwz 0,0x3ec(31); li 9,2; cmpwi 0,8; bne 10f; li 9,1; 10:; stw 9,0x3ec(31); 11:; lwz 0,0x3ec(31); cmpwi 0,1; beq 12f; cmpwi 0,5; beq 12f; cmpwi 0,8; bne 13f; 12:; lis 9,-32697; addi 11,9,21724; lwz 10,0x54dc(9); b 14f; 13:; lis 9,-32697; addi 11,9,21736; lwz 10,0x54e8(9); 14:; lwz 8,0x8(11); lwz 0,0x4(11); stw 10,0x0(30); stw 0,0x4(30); stw 8,0x8(30); lfs f11,0x8(30); addi 10,1,8; lfs f0,0x0(30); lfs f13,0x4(30); lfs f12,-32620(13); fmuls f11,f11,f12; fmuls f0,f0,f12; stfs f11,0x10(1); fmuls f13,f13,f12; stfs f0,0x8(1); stfs f13,0xc(1); lwz 11,0x8(1); lwz 0,0x8(10); lwz 9,0x4(10); stw 0,0x8(29); stw 11,0x0(29); stw 9,0x4(29); lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"

extern "C" void _s800321A0_0();
extern "C" void _s800321A0_1();
extern "C" void _s800321A0_2();
extern "C" void _s800321A0_3();
extern "C" void _s800321A0_4();
extern "C" void _s800321A0_5();
extern "C" void _s800321A0_6();

struct ESim {
    void UpdateSkillMeter_EVec3();
};

void ESim::UpdateSkillMeter_EVec3() {
}
