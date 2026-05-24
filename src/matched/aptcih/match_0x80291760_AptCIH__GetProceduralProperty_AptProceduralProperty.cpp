// 0x80291760 AptCIH::GetProceduralProperty(AptProceduralProperty) (976 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,3; cmpwi 4,5; beq 5f; bgt 1f; cmpwi 4,2; beq 11f; bgt 0f; cmpwi 4,0; beq 27f; cmpwi 4,1; beq 28f; b 36f; 0:; cmpwi 4,3; beq 18f; cmpwi 4,4; beq 3f; b 36f; 1:; cmpwi 4,8; beq 31f; bgt 2f; cmpwi 4,6; beq 6f; cmpwi 4,7; beq 29f; b 36f; 2:; cmpwi 4,10; beq 33f; blt 32f; cmpwi 4,11; beq 35f; b 36f; 3:; mr 3,30; addi 4,1,8; bl _s80291760_0; lfs f0,0x10(1); lis 9,-32704; lfs f13,0x8(1); 4:; lfs f12,0x5af0(9); fsubs f1,f0,f13; fcmpu 0,f1,f12; cror 3,2,1; bso 37f; fmr f1,f12; b 37f; 5:; mr 3,30; addi 4,1,8; bl _s80291760_1; lfs f0,0x14(1); lis 9,-32704; lfs f13,0xc(1); b 4b; 6:; lwz 9,0x60(30); cmpwi 9,0; beq 7f; lfs f1,0x0(9); b 37f; 7:; lis 9,-32704; lfs f0,0x14(30); lfs f1,0x5af0(9); fcmpu 0,f0,f1; bne 8f; lfs f0,0x18(30); fcmpu 0,f0,f1; beq 37f; 8:; addi 31,30,16; lis 9,-32704; lfs f13,0x5af0(9); lfs f0,0x4(31); fcmpu 0,f0,f13; bne 9f; lfs f0,0x8(31); fcmpu 0,f0,f13; bne 9f; lis 9,-32704; lfs f1,0x5af4(9); b 10f; 9:; mr 3,31; bl _s80291760_2; lfs f0,0x0(31); fdivs f1,f0,f1; 10:; bl _s80291760_3; lis 9,-32704; lis 11,-32704; lfs f13,0x5af8(9); lfs f12,0x14(30); lfs f0,0x5af0(11); fmuls f1,f1,f13; fcmpu 0,f12,f0; cror 3,2,1; bso 37f; fneg f1,f1; b 37f; 11:; lis 9,-32704; lfs f0,0x14(30); lfs f13,0x5af0(9); fcmpu 0,f0,f13; bne 12f; lfs f0,0x18(30); fcmpu 0,f0,f13; bne 12f; lis 9,-32704; lfs f0,0x10(30); b 30f; 12:; lwz 0,0x60(30); cmpwi 0,0; beq 15f; addi 31,30,16; lis 9,-32704; lfs f13,0x5af0(9); lfs f0,0x4(31); fcmpu 0,f0,f13; bne 13f; lfs f0,0x8(31); fcmpu 0,f0,f13; bne 13f; lis 9,-32704; lfs f1,0x5af4(9); b 14f; 13:; mr 3,31; bl _s80291760_4; lfs f0,0x0(31); fdivs f1,f0,f1; 14:; bl _s80291760_5; lfs f0,0x10(30); b 22f; 15:; addi 31,30,16; lis 9,-32704; lfs f13,0x5af0(9); lfs f0,0x4(31); fcmpu 0,f0,f13; bne 16f; lfs f0,0x8(31); fcmpu 0,f0,f13; bne 16f; lis 9,-32704; lfs f13,0x5af4(9); b 17f; 16:; mr 3,31; bl _s80291760_6; lfs f0,0x0(31); fdivs f13,f0,f1; 17:; lfs f1,0x10(30); b 26f; 18:; lis 9,-32704; lfs f0,0x14(30); lfs f13,0x5af0(9); fcmpu 0,f0,f13; bne 19f; lfs f0,0x18(30); fcmpu 0,f0,f13; bne 19f; lis 9,-32704; lfs f0,0x1c(30); b 30f; 19:; lwz 0,0x60(30); cmpwi 0,0; beq 23f; addi 31,30,16; lis 9,-32704; lfs f13,0x5af0(9); lfs f0,0x4(31); fcmpu 0,f0,f13; bne 20f; lfs f0,0x8(31); fcmpu 0,f0,f13; bne 20f; lis 9,-32704; lfs f1,0x5af4(9); b 21f; 20:; mr 3,31; bl _s80291760_7; lfs f0,0x0(31); fdivs f1,f0,f1; 21:; bl _s80291760_8; lfs f0,0x1c(30); 22:; lis 9,-32704; lfs f13,0x5afc(9); fdivs f0,f0,f1; fmuls f1,f0,f13; b 37f; 23:; addi 31,30,16; lis 9,-32704; lfs f13,0x5af0(9); lfs f0,0x4(31); fcmpu 0,f0,f13; bne 24f; lfs f0,0x8(31); fcmpu 0,f0,f13; bne 24f; lis 9,-32704; lfs f13,0x5af4(9); b 25f; 24:; mr 3,31; bl _s80291760_9; lfs f0,0x0(31); fdivs f13,f0,f1; 25:; lfs f1,0x1c(30); 26:; lis 9,-32704; lfs f0,0x5afc(9); fdivs f1,f1,f13; fmuls f1,f1,f0; b 37f; 27:; lfs f1,0x20(30); b 37f; 28:; lfs f1,0x24(30); b 37f; 29:; lis 9,-32704; lfs f0,0x28(30); 30:; lfs f1,0x5afc(9); fmuls f1,f0,f1; b 37f; 31:; lis 9,-32704; lfs f0,0x3c(30); b 34f; 32:; lis 9,-32704; lfs f0,0x40(30); b 34f; 33:; lis 9,-32704; lfs f0,0x44(30); 34:; lfs f1,0x5b00(9); fmuls f1,f0,f1; b 37f; 35:; lwz 0,0x5c(30); lis 10,17200; lis 11,-32704; rlwinm 0,0,21,31,31; lfd f0,0x5b08(11); stw 0,0x1c(1); stw 10,0x18(1); lfd f1,0x18(1); fsub f1,f1,f0; frsp f1,f1; b 37f; 36:; lis 9,-32704; lfs f1,0x5b10(9); 37:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"

extern "C" void _s80291760_0();
extern "C" void _s80291760_1();
extern "C" void _s80291760_2();
extern "C" void _s80291760_3();
extern "C" void _s80291760_4();
extern "C" void _s80291760_5();
extern "C" void _s80291760_6();
extern "C" void _s80291760_7();
extern "C" void _s80291760_8();
extern "C" void _s80291760_9();

struct AptCIH {
    void GetProceduralProperty_AptProceduralProperty();
};

void AptCIH::GetProceduralProperty_AptProceduralProperty() {
}
