// 0x8024E9EC GetApploaderPosition (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-72(1); stw 31,0x44(1); lwz 3,-23668(13); cmpwi 3,0; beq 0f; b 7f; 0:; lis 31,-32768; lwz 0,0x30f4(31); cmpwi 0,0; beq 5f; li 3,64; li 4,32; bl _s8024E9EC_0; lwz 6,0x30f4(31); mr 31,3; mr 4,31; addi 3,1,8; li 5,64; li 7,0; li 8,0; bl _s8024E9EC_1; b 1f; 1:; b 2f; 2:; b 4f; 3:; bl _s8024E9EC_2; cmpwi 3,0; bne 4f; li 3,0; bl _s8024E9EC_3; 4:; addi 3,1,8; bl _s8024E9EC_4; cmpwi 3,0; bne 3b; lis 3,-32768; lwz 0,0x38(31); lwz 3,0x30f4(3); add 0,3,0; stw 0,-23668(13); b 6f; 5:; li 0,9280; stw 0,-23668(13); 6:; lwz 3,-23668(13); 7:; lwz 0,0x4c(1); lwz 31,0x44(1); addi 1,1,72; mtspr 8,0"
extern "C" void _s8024E9EC_0();
extern "C" void _s8024E9EC_1();
extern "C" void _s8024E9EC_2();
extern "C" void _s8024E9EC_3();
extern "C" void _s8024E9EC_4();
extern "C" void f_8024E9EC() {}
