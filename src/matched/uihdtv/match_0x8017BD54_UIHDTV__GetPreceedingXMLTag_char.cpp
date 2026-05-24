// 0x8017BD54 UIHDTV::GetPreceedingXMLTag(char (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,4; mr 31,5; bl _s8017BD54_0; li 27,0; cmpwi 3,0; beq 0f; li 27,1; 0:; lwz 3,-31512(13); bl _s8017BD54_1; lwz 29,-31512(13); subf 30,3,31; subf 30,27,30; add 30,28,30; mr 3,29; bl _s8017BD54_2; mr 5,3; mr 4,29; mr 3,30; bl _s8017BD54_3; cmpwi 3,0; li 3,0; beq 2f; lwz 3,-31508(13); bl _s8017BD54_4; lwz 29,-31508(13); subf 30,3,31; subf 30,27,30; add 30,28,30; mr 3,29; bl _s8017BD54_5; mr 5,3; mr 4,29; mr 3,30; bl _s8017BD54_6; cmpwi 3,0; li 3,1; beq 2f; lwz 3,-31504(13); bl _s8017BD54_7; lwz 29,-31504(13); subf 30,3,31; subf 30,27,30; add 30,28,30; mr 3,29; bl _s8017BD54_8; mr 5,3; mr 4,29; mr 3,30; bl _s8017BD54_9; cmpwi 3,0; beq 1f; lwz 3,-31500(13); bl _s8017BD54_10; lwz 29,-31500(13); subf 30,3,31; subf 30,27,30; add 30,28,30; mr 3,29; bl _s8017BD54_11; mr 5,3; mr 4,29; mr 3,30; bl _s8017BD54_12; cmpwi 3,0; li 3,3; beq 2f; li 3,4; b 2f; 1:; li 3,2; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8017BD54_0();
extern "C" void _s8017BD54_1();
extern "C" void _s8017BD54_2();
extern "C" void _s8017BD54_3();
extern "C" void _s8017BD54_4();
extern "C" void _s8017BD54_5();
extern "C" void _s8017BD54_6();
extern "C" void _s8017BD54_7();
extern "C" void _s8017BD54_8();
extern "C" void _s8017BD54_9();
extern "C" void _s8017BD54_10();
extern "C" void _s8017BD54_11();
extern "C" void _s8017BD54_12();

struct UIHDTV {
    void GetPreceedingXMLTag();
};

void UIHDTV::GetPreceedingXMLTag() {
}
