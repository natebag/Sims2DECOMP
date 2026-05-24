// 0x8019828C CASGeneticsTarget::BeginGenerate(void) (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lwz 0,-31440(13); mr 31,3; li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; bne 4f; lis 9,-32705; lis 3,-32705; addi 9,9,-15588; addi 3,3,-14976; stw 9,0x8(1); li 4,0; li 5,0; li 6,1; addi 7,1,8; bl _s8019828C_0; lis 9,-32697; lwz 0,0x6200(9); cmpwi 0,0; beq 1f; lwz 0,0x414(31); cmpwi 0,0; beq 1f; lwz 11,0x418(31); cmpwi 11,0; beq 1f; lwz 9,0x0(11); li 0,1; lwz 10,-26564(13); ori 9,9,8; stw 0,0x10(11); stw 9,0x0(11); lwz 11,0x0(10); lwz 4,0x414(31); lha 3,0xb0(11); lwz 0,0xb4(11); add 3,10,3; lwz 5,0x418(31); mtspr 8,0; blrl; 1:; lwz 0,0x300(31); li 30,26; li 29,26; rlwinm 0,0,0,28,26; stw 0,0x300(31); bl _s8019828C_1; mr 5,3; li 4,0; divwu 0,5,30; mr 3,31; mulli 0,0,26; subf 5,0,5; bl _s8019828C_2; bl _s8019828C_3; mr 5,3; li 4,1; divwu 30,5,30; mr 3,31; mulli 30,30,26; subf 5,30,5; bl _s8019828C_4; 2:; bl _s8019828C_5; mr 5,3; li 4,2; divwu 0,5,29; mr 3,31; mulli 0,0,26; subf 5,0,5; bl _s8019828C_6; lwz 9,0x9c(31); lwz 0,0xa4(31); cmpw 9,0; beq 2b; li 30,26; 3:; bl _s8019828C_7; mr 5,3; li 4,3; divwu 0,5,30; mr 3,31; mulli 0,0,26; subf 5,0,5; bl _s8019828C_8; lwz 9,0xa0(31); lwz 0,0xa8(31); cmpw 9,0; beq 3b; mr 3,31; li 4,0; bl _s8019828C_9; mr 3,31; li 4,1; bl _s8019828C_10; li 0,3; li 3,1; stw 0,-31440(13); b 5f; 4:; li 3,0; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s8019828C_0();
extern "C" void _s8019828C_1();
extern "C" void _s8019828C_2();
extern "C" void _s8019828C_3();
extern "C" void _s8019828C_4();
extern "C" void _s8019828C_5();
extern "C" void _s8019828C_6();
extern "C" void _s8019828C_7();
extern "C" void _s8019828C_8();
extern "C" void _s8019828C_9();
extern "C" void _s8019828C_10();

struct CASGeneticsTarget {
    void BeginGenerate();
};

void CASGeneticsTarget::BeginGenerate() {
}
