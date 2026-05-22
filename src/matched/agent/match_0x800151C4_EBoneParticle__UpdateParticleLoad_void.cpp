// 0x800151C4 EBoneParticle::UpdateParticleLoad(void) (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 31,3; lwz 28,0x64(31); cmpwi 28,0; bne 3f; lwz 0,0x70(31); cmpwi 0,0; li 3,1; bne 5f; lis 3,-32692; lwz 4,0x60(31); addi 3,3,6092; bl _s800151C4_0; stw 3,0x70(31); cmpwi 3,0; beq 4f; lwz 5,0x60(31); lis 4,-32707; lwz 29,0x14(3); addi 4,4,-7996; addi 3,1,8; crxor 6,6,6; bl _s800151C4_1; li 3,196; bl _s800151C4_2; mr 30,3; bl _s800151C4_3; lis 9,-32698; stw 30,0x68(31); addi 9,9,-21528; mr 3,30; stw 9,0x0(30); mr 6,29; addi 4,1,8; li 5,0; bl _s800151C4_4; cmpwi 3,-1; bne 1f; lwz 11,0x68(31); cmpwi 11,0; beq 0f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 0:; stw 28,0x68(31); li 3,1; b 5f; 1:; lwz 0,0x48(31); cmpwi 0,0; beq 2f; lwz 3,0x68(31); lis 4,2048; li 5,1; bl _s800151C4_5; 2:; lwz 3,0x68(31); lis 4,-32717; lwz 5,0x70(31); addi 4,4,-18888; bl _s800151C4_6; lwz 3,0x68(31); li 5,1; lwz 4,-22708(13); bl _s800151C4_7; li 3,1; b 5f; 3:; cmpwi 28,1; bne 4f; lwz 0,0x74(31); cmpwi 0,0; li 3,1; bne 5f; lis 3,-32692; lwz 4,0x60(31); addi 3,3,-644; bl _s800151C4_8; cmpwi 3,0; stw 3,0x74(31); beq 4f; bl _s800151C4_9; lwz 4,0x74(31); mr 5,31; bl _s800151C4_10; stw 3,0x6c(31); cmpwi 3,0; li 3,0; beq 5f; li 3,1; b 5f; 4:; li 3,0; 5:; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s800151C4_0();
extern "C" void _s800151C4_1();
extern "C" void _s800151C4_2();
extern "C" void _s800151C4_3();
extern "C" void _s800151C4_4();
extern "C" void _s800151C4_5();
extern "C" void _s800151C4_6();
extern "C" void _s800151C4_7();
extern "C" void _s800151C4_8();
extern "C" void _s800151C4_9();
extern "C" void _s800151C4_10();
extern "C" void f_800151C4() {}
