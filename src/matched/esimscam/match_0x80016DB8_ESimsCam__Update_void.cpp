// 0x80016DB8 ESimsCam::Update(void) (512 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 3,0x0(31); bl _s80016DB8_0; mr 3,31; bl _s80016DB8_1; cmpwi 3,0; beq 0f; mr 3,31; li 4,5; bl _s80016DB8_2; b 1f; 0:; mr 3,31; li 4,6; bl _s80016DB8_3; 1:; lis 9,-32697; lwz 0,0x4(31); addi 9,9,24012; addi 29,9,188; rlwinm 0,0,2,0,29; lwzx 11,29,0; cmpwi 11,0; beq 3f; lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(31); mr 30,3; li 4,17; rlwinm 0,0,2,0,29; lwzx 9,29,0; lwz 10,0x0(9); lwz 11,0x4(10); lha 3,0x260(11); lwz 0,0x264(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; cmpwi 30,0; beq 2f; lwz 0,0x10(30); cmpwi 0,1; bne 2f; mr 3,31; li 4,4; bl _s80016DB8_4; b 3f; 2:; lwz 0,0x4a8(31); cmpwi 0,4; bne 3f; mr 3,31; li 4,-1; bl _s80016DB8_5; 3:; lwz 0,0x4(31); lis 9,-32697; addi 9,9,24012; mr 4,0; addi 9,9,280; rlwinm 0,0,2,0,29; lwzx 9,9,0; cmpwi 9,0; beq 5f; lwz 0,0x160(9); li 9,0; cmpwi 0,0; beq 4f; cmpwi 0,8; beq 4f; li 9,1; 4:; cmpwi 9,0; beq 5f; mr 3,31; bl _s80016DB8_6; b 12f; 5:; lis 9,-32697; rlwinm 10,4,2,0,29; addi 9,9,24012; addi 9,9,280; lwzx 11,9,10; lwz 0,0x160(11); cmpwi 0,8; beq 7f; lwz 0,0x3cc(31); cmpwi 0,1; beq 6f; bgt 7f; cmpwi 0,0; bne 7f; mr 3,31; bl _s80016DB8_7; b 7f; 6:; mr 3,31; bl _s80016DB8_8; 7:; lwz 0,0x564(31); cmpwi 0,0; bne 8f; lwz 0,0x568(31); cmpwi 0,0; beq 9f; 8:; li 0,0; b 11f; 9:; mr 3,31; bl _s80016DB8_9; mr 30,3; mr 3,31; bl _s80016DB8_10; cmpwi 30,0; li 0,0; bne 10f; cmpwi 3,0; beq 11f; 10:; li 0,1; 11:; stw 0,0x8(31); mr 3,31; bl _s80016DB8_11; 12:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80016DB8_0();
extern "C" void _s80016DB8_1();
extern "C" void _s80016DB8_2();
extern "C" void _s80016DB8_3();
extern "C" void _s80016DB8_4();
extern "C" void _s80016DB8_5();
extern "C" void _s80016DB8_6();
extern "C" void _s80016DB8_7();
extern "C" void _s80016DB8_8();
extern "C" void _s80016DB8_9();
extern "C" void _s80016DB8_10();
extern "C" void _s80016DB8_11();

struct ESimsCam {
    void Update();
};

void ESimsCam::Update() {
}
