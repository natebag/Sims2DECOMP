// 0x802E9CDC EAnimController::Compute(EMat4 (1100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 21,0x1c(1); stw 0,0x4c(1); mr 31,3; mr 22,4; lwz 0,0x30(31); li 23,0; cmpw 0,5; bne 0f; lwz 0,0x74(31); cmpwi 0,0; beq 26f; 0:; lwz 0,0x0(31); stw 5,0x30(31); andi. 9,0,2; beq 26f; lwz 0,0x60(31); cmpwi 0,0; beq 26f; lwz 0,0x40(31); li 30,0; mr 10,0; cmpw 30,0; bge 25f; lwz 9,0x44(31); lwz 0,0xa8(9); cmpwi 0,1; beq 2f; addi 9,9,168; mr 11,10; 1:; addi 30,30,1; cmpw 30,11; bge 25f; lwzu 0,0xb0(9); cmpwi 0,1; bne 1b; 2:; cmpw 30,10; bge 25f; mr 3,31; bl _s802E9CDC_0; cmpwi 3,-1; bne 3f; li 3,0; lwz 28,0x44(31); b 4f; 3:; mulli 9,3,176; lwz 0,0x44(31); add 28,0,9; 4:; lwz 9,0x24(31); cmpwi 9,0; beq 5f; lwz 9,0x18(9); mtspr 9,9; b 6f; 5:; li 0,0; mtspr 9,0; 6:; mfspr 9,9; lis 21,-32693; cmpwi 9,0; beq 10f; cmpwi 3,-1; beq 8f; lwz 0,0x7c(28); li 9,1; cmpwi 0,0; bne 7f; li 9,0; 7:; cmpwi 9,0; beq 8f; lis 9,-32702; lfs f13,0x50(28); lfs f0,-4588(9); fcmpu 0,f13,f0; bne 8f; lwz 0,0x9c(28); cmpwi 0,0; beq 10f; 8:; lis 9,-32702; lwz 10,0xc(31); lfs f13,-4584(9); lis 11,-32702; lis 9,-32702; lfs f0,-4588(11); lfs f12,-4580(9); addi 10,10,44; lis 21,-32693; li 8,0; 9:; stw 8,-44(10); stfs f13,-32(10); stfs f13,-36(10); stfs f13,-40(10); stfs f0,-28(10); stfs f13,0x10(1); stfs f13,0xc(1); stfs f13,0x8(1); lwz 11,0xc(1); lwz 0,0x8(1); lwz 9,0x10(1); stw 0,-24(10); stw 11,-20(10); stw 9,-16(10); stfs f0,0x10(1); stfs f0,0xc(1); stfs f0,0x8(1); lwz 11,0xc(1); lwz 0,0x8(1); lwz 9,0x10(1); stw 0,-12(10); stw 11,-8(10); stw 9,-4(10); stfs f0,0x8(1); stfs f0,0xc(1); stfs f0,0x10(1); lwz 0,0x8(1); lwz 9,0xc(1); lwz 11,0x10(1); stw 0,0x0(10); stw 9,0x4(10); stw 11,0x8(10); stfs f0,0xc(10); stfs f12,0x10(10); stfs f13,0x14(10); addi 10,10,68; bdnz 9b; 10:; li 0,0; lwz 5,0xc(31); stw 0,0x5c(31); mr 3,31; mr 4,28; li 6,0; bl _s802E9CDC_1; li 30,0; lwz 11,0x8c(28); cmpwi 11,0; beq 13f; 11:; lwz 9,0x1c(11); lwz 0,0x30(9); andis. 10,0,8; beq 12f; mr 30,9; 12:; lwz 11,0x10(11); cmpwi 11,0; bne 11b; 13:; cmpwi 30,0; beq 14f; lis 9,-32693; mr 4,30; addi 27,9,-2144; li 6,0; mr 5,27; mr 3,31; bl _s802E9CDC_2; lwz 6,0xc(31); mr 4,30; mr 5,27; mr 3,31; bl _s802E9CDC_3; 14:; lwz 0,0x6c(31); li 8,0; li 25,0; addic. 30,0,-1; blt 21f; 15:; lwz 11,0x70(31); rlwinm 0,8,4,0,27; lwz 10,0x44(31); add 0,0,8; lbzx 9,11,30; rlwinm 0,0,8,0,23; addi 11,21,-10848; addi 26,30,-1; extsb 9,9; add 29,0,11; mulli 9,9,176; addi 24,8,1; li 30,0; add 28,10,9; lwz 11,0x8c(28); cmpwi 11,0; beq 18f; 16:; lwz 9,0x1c(11); lwz 0,0x30(9); andis. 10,0,8; beq 17f; mr 30,9; 17:; lwz 11,0x10(11); cmpwi 11,0; bne 16b; 18:; mr 3,31; mr 4,28; mr 5,29; li 6,0; bl _s802E9CDC_4; cmpwi 3,0; beq 20f; cmpwi 30,0; beq 19f; lis 9,-32693; mr 4,30; addi 27,9,-2144; li 6,0; mr 5,27; mr 3,31; bl _s802E9CDC_5; mr 4,30; mr 5,27; mr 3,31; mr 6,29; bl _s802E9CDC_6; 19:; cmpwi 23,0; beq 20f; mr 4,23; mr 5,25; mr 3,31; mr 6,29; bl _s802E9CDC_7; 20:; mr 8,24; mr 25,29; rlwinm 0,8,1,31,31; mr 23,28; add 0,8,0; mr. 30,26; rlwinm 0,0,0,0,30; subf 8,0,8; bge 15b; 21:; cmpwi 23,0; beq 22f; lwz 6,0xc(31); mr 4,23; mr 5,25; mr 3,31; bl _s802E9CDC_8; 22:; lwz 30,0x38(31); lis 9,-32693; lwz 0,0x40(31); addi 25,9,-10848; cmpw 30,0; bge 25f; mulli 29,30,176; 23:; lwz 0,0x44(31); mr 3,31; mr 5,25; mr 6,22; add 28,0,29; mr 4,28; bl _s802E9CDC_9; cmpwi 3,0; beq 24f; lwz 6,0xc(31); mr 4,28; mr 3,31; mr 5,25; bl _s802E9CDC_10; 24:; lwz 0,0x40(31); addi 30,30,1; addi 29,29,176; cmpw 30,0; blt 23b; 25:; mr 3,31; mr 4,22; bl _s802E9CDC_11; lwz 0,0x64(31); cmpwi 0,0; beq 26f; mr 4,22; lwz 6,0x10(31); lwz 3,0x68(31); mtspr 8,0; lwz 5,0x24(31); blrl; 26:; lwz 0,0x4c(1); mtspr 8,0; lmw 21,0x1c(1); addi 1,1,72"

extern "C" void _s802E9CDC_0();
extern "C" void _s802E9CDC_1();
extern "C" void _s802E9CDC_2();
extern "C" void _s802E9CDC_3();
extern "C" void _s802E9CDC_4();
extern "C" void _s802E9CDC_5();
extern "C" void _s802E9CDC_6();
extern "C" void _s802E9CDC_7();
extern "C" void _s802E9CDC_8();
extern "C" void _s802E9CDC_9();
extern "C" void _s802E9CDC_10();
extern "C" void _s802E9CDC_11();

struct EAnimController {
    void Compute();
};

void EAnimController::Compute() {
}
