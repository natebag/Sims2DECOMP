// 0x8036A278 ERSoundTrackData::Load(EFile (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 30,3; mr. 29,4; beq 19f; addi 3,1,8; bl _s8036A278_0; lis 5,21332; addi 3,1,8; mr 4,29; ori 5,5,21060; li 6,1; li 7,1; bl _s8036A278_1; cmpwi 3,0; bne 0f; addi 3,1,8; li 4,2; bl _s8036A278_2; b 19f; 0:; addi 3,1,8; bl _s8036A278_3; lwz 11,0x18(1); addi 3,30,20; lwz 0,0x10(30); addi 6,1,32; lwz 10,0x14(30); rlwinm 31,11,30,2,31; stw 9,0x20(1); rlwimi 0,11,8,0,23; stw 0,0x10(30); lwz 4,0x4(3); subf 0,10,4; srawi 0,0,2; cmplw 31,0; bge 3f; rlwinm 0,31,2,0,29; add 0,0,10; lwz 11,0x4(3); mr 9,0; cmpw 0,11; beq 2f; 1:; addi 9,9,4; cmpw 9,11; bne 1b; 2:; stw 0,0x4(3); b 4f; 3:; subf 5,0,31; bl _s8036A278_4; 4:; lwz 9,0x28(29); lwz 4,0x14(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,29,3; lwz 5,0x18(1); mtspr 8,0; blrl; cmpwi 31,0; beq 18f; mr 29,31; li 31,0; 5:; lwz 9,0x14(30); lbzx 0,9,31; mr 3,9; extsb 0,0; cmpwi 0,69; bgt 9f; cmpwi 0,68; bge 13f; cmpwi 0,14; beq 13f; bgt 7f; cmpwi 0,6; beq 14f; bgt 6f; cmpwi 0,4; blt 17f; b 16f; 6:; cmpwi 0,9; beq 13f; b 17f; 7:; cmpwi 0,24; beq 15f; bgt 8f; cmpwi 0,20; bgt 17f; cmpwi 0,16; blt 17f; b 14f; 8:; cmpwi 0,39; beq 13f; cmpwi 0,51; beq 13f; b 17f; 9:; cmpwi 0,84; bgt 11f; cmpwi 0,83; bge 13f; cmpwi 0,75; beq 14f; bgt 10f; cmpwi 0,72; beq 15f; b 17f; 10:; cmpwi 0,77; beq 14f; b 17f; 11:; cmpwi 0,88; bgt 12f; cmpwi 0,86; bge 13f; b 16f; 12:; cmpwi 0,89; beq 14f; b 17f; 13:; add 3,3,31; addi 3,3,1; bl _s8036A278_5; b 17f; 14:; add 3,3,31; addi 3,3,1; bl _s8036A278_6; lwz 3,0x14(30); add 3,3,31; addi 3,3,2; bl _s8036A278_7; b 17f; 15:; add 3,3,31; addi 3,3,1; bl _s8036A278_8; lwz 3,0x14(30); add 3,3,31; addi 3,3,2; bl _s8036A278_9; lwz 3,0x14(30); add 3,3,31; addi 3,3,3; bl _s8036A278_10; b 17f; 16:; add 3,3,31; addi 3,3,1; bl _s8036A278_11; 17:; addi 31,31,4; addic. 29,29,-1; bne 5b; 18:; addi 3,1,8; li 4,2; bl _s8036A278_12; 19:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"

extern "C" void _s8036A278_0();
extern "C" void _s8036A278_1();
extern "C" void _s8036A278_2();
extern "C" void _s8036A278_3();
extern "C" void _s8036A278_4();
extern "C" void _s8036A278_5();
extern "C" void _s8036A278_6();
extern "C" void _s8036A278_7();
extern "C" void _s8036A278_8();
extern "C" void _s8036A278_9();
extern "C" void _s8036A278_10();
extern "C" void _s8036A278_11();
extern "C" void _s8036A278_12();

struct ERSoundTrackData {
    void Load_EFile();
};

void ERSoundTrackData::Load_EFile() {
}
