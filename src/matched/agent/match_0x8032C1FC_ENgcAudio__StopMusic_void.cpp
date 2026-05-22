// 0x8032C1FC ENgcAudio::StopMusic(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); lwz 0,-26576(13); cmpwi 0,0; beq 3f; addi 0,3,64; lwz 9,0x40(3); stw 0,0x8(1); li 4,-1; li 28,-1; lis 29,-32693; lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; lis 9,-32692; addi 31,9,9696; addi 30,31,4284; 0:; lwz 0,0x0(31); cmpwi 0,-1; beq 2f; lwz 4,0x40(31); cmpwi 4,-1; beq 2f; lwz 3,-26560(13); bl _s8032C1FC_0; cmpwi 3,0; beq 1f; lwz 4,0x0(31); addi 3,29,14424; li 5,1; bl _s8032C1FC_1; 1:; stw 28,0x0(31); 2:; addi 31,31,68; cmplw 31,30; ble 0b; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8032C1FC_0();
extern "C" void _s8032C1FC_1();
extern "C" void f_8032C1FC() {}
