// 0x8004BA38 EParticleEffect::UpdateParticleEffectLoad(void) (564 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 30,3; lwz 28,0x64(30); cmpwi 28,0; bne 7f; lwz 0,0x68(30); cmpwi 0,0; li 3,1; bne 9f; lis 3,-32692; lwz 4,0x60(30); addi 3,3,6092; bl _s8004BA38_0; stw 3,0x68(30); cmpwi 3,0; beq 8f; lwz 29,0x14(3); lis 4,-32707; lwz 5,0x60(30); addi 4,4,12636; addi 3,1,8; crxor 6,6,6; bl _s8004BA38_1; lwz 0,0x108(29); andis. 9,0,512; beq 0f; li 3,196; bl _s8004BA38_2; mr 31,3; bl _s8004BA38_3; lis 9,-32698; mr 6,29; addi 9,9,-15344; mr 3,31; stw 9,0x0(31); addi 4,1,8; li 5,0; bl _s8004BA38_4; cmpwi 3,-1; stw 31,0x58(30); bne 1f; b 3f; 0:; andis. 9,0,32; beq 2f; li 3,196; bl _s8004BA38_5; mr 31,3; bl _s8004BA38_6; lis 9,-32698; mr 6,29; addi 9,9,-15000; mr 3,31; stw 9,0x0(31); addi 4,1,8; li 5,0; bl _s8004BA38_7; cmpwi 3,-1; stw 31,0x58(30); beq 3f; 1:; lwz 4,-22700(13); mr 3,31; li 5,1; bl _s8004BA38_8; b 6f; 2:; li 3,196; bl _s8004BA38_9; mr 31,3; bl _s8004BA38_10; lis 9,-32698; mr 6,29; addi 9,9,-21528; mr 3,31; stw 9,0x0(31); addi 4,1,8; li 5,0; bl _s8004BA38_11; cmpwi 3,-1; stw 31,0x58(30); bne 5f; 3:; cmpwi 31,0; beq 4f; lwz 9,0x0(31); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; 4:; stw 28,0x58(30); li 3,1; b 9f; 5:; lwz 4,-22708(13); mr 3,31; li 5,1; bl _s8004BA38_12; 6:; lwz 3,0x58(30); lis 4,-32717; lwz 5,0x68(30); addi 4,4,-18888; bl _s8004BA38_13; lwz 3,0x58(30); li 4,2; li 5,0; bl _s8004BA38_14; li 3,1; b 9f; 7:; cmpwi 28,1; bne 8f; lwz 0,0x6c(30); cmpwi 0,0; li 3,1; bne 9f; lis 3,-32692; lwz 4,0x60(30); addi 3,3,-644; bl _s8004BA38_15; cmpwi 3,0; stw 3,0x6c(30); beq 8f; bl _s8004BA38_16; lwz 4,0x6c(30); mr 5,30; bl _s8004BA38_17; mr 9,3; stw 9,0x5c(30); cmpwi 9,0; beq 8f; lwz 0,0x140(9); li 3,1; rlwinm 0,0,0,22,19; stw 0,0x140(9); b 9f; 8:; li 3,0; 9:; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s8004BA38_0();
extern "C" void _s8004BA38_1();
extern "C" void _s8004BA38_2();
extern "C" void _s8004BA38_3();
extern "C" void _s8004BA38_4();
extern "C" void _s8004BA38_5();
extern "C" void _s8004BA38_6();
extern "C" void _s8004BA38_7();
extern "C" void _s8004BA38_8();
extern "C" void _s8004BA38_9();
extern "C" void _s8004BA38_10();
extern "C" void _s8004BA38_11();
extern "C" void _s8004BA38_12();
extern "C" void _s8004BA38_13();
extern "C" void _s8004BA38_14();
extern "C" void _s8004BA38_15();
extern "C" void _s8004BA38_16();
extern "C" void _s8004BA38_17();
extern "C" void f_8004BA38() {}
