// 0x8024E94C StopStreaming (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); lwz 0,-23732(13); cmpwi 0,0; bne 6f; bl _s8024E94C_0; lbz 0,0x8(3); cmplwi 0,0; beq 0f; li 0,1; b 1f; 0:; li 0,0; 1:; cmpwi 0,0; beq 6f; li 3,0; bl _s8024E94C_1; li 3,0; bl _s8024E94C_2; addi 3,1,8; li 4,0; bl _s8024E94C_3; b 2f; 2:; b 3f; 3:; b 5f; 4:; bl _s8024E94C_4; cmpwi 3,0; bne 5f; li 3,0; bl _s8024E94C_5; 5:; addi 3,1,8; bl _s8024E94C_6; cmpwi 3,0; bne 4b; li 3,0; bl _s8024E94C_7; 6:; lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s8024E94C_0();
extern "C" void _s8024E94C_1();
extern "C" void _s8024E94C_2();
extern "C" void _s8024E94C_3();
extern "C" void _s8024E94C_4();
extern "C" void _s8024E94C_5();
extern "C" void _s8024E94C_6();
extern "C" void _s8024E94C_7();
extern "C" void f_8024E94C() {}
