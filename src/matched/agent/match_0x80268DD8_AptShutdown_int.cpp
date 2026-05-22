// 0x80268DD8 AptShutdown(int) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32694; li 0,1; addi 30,9,-16032; mr 31,3; stw 0,0x5c(30); bl _s80268DD8_0; lwz 3,-23008(13); bl _s80268DD8_1; li 3,1; bl _s80268DD8_2; lwz 3,-23000(13); cmpwi 3,0; beq 0f; li 4,3; bl _s80268DD8_3; 0:; lwz 3,-22996(13); cmpwi 3,0; beq 1f; li 4,3; bl _s80268DD8_4; 1:; lwz 3,-22992(13); cmpwi 3,0; beq 2f; li 4,3; bl _s80268DD8_5; 2:; mr 3,31; bl _s80268DD8_6; bl _s80268DD8_7; bl _s80268DD8_8; bl _s80268DD8_9; lwz 3,-27600(13); bl _s80268DD8_10; lwz 3,-23008(13); cmpwi 3,0; beq 3f; li 4,3; bl _s80268DD8_11; 3:; lwz 3,-27596(13); li 31,0; stw 31,-23008(13); cmpwi 3,0; beq 4f; li 4,3; bl _s80268DD8_12; 4:; lwz 4,-23024(13); stw 31,-27596(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80268DD8_13; 5:; lis 9,-32700; lhz 11,-6476(9); addi 0,9,-6476; stw 0,-23024(13); addi 11,11,1; sth 11,-6476(9); bl _s80268DD8_14; lwz 3,-27600(13); bl _s80268DD8_15; lwz 3,-27600(13); cmpwi 3,0; beq 6f; li 4,3; bl _s80268DD8_16; 6:; mr 3,30; stw 31,-27600(13); stw 31,-26904(13); bl _s80268DD8_17; bl _s80268DD8_18; bl _s80268DD8_19; bl _s80268DD8_20; bl _s80268DD8_21; stw 31,-22988(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80268DD8_0();
extern "C" void _s80268DD8_1();
extern "C" void _s80268DD8_2();
extern "C" void _s80268DD8_3();
extern "C" void _s80268DD8_4();
extern "C" void _s80268DD8_5();
extern "C" void _s80268DD8_6();
extern "C" void _s80268DD8_7();
extern "C" void _s80268DD8_8();
extern "C" void _s80268DD8_9();
extern "C" void _s80268DD8_10();
extern "C" void _s80268DD8_11();
extern "C" void _s80268DD8_12();
extern "C" void _s80268DD8_13();
extern "C" void _s80268DD8_14();
extern "C" void _s80268DD8_15();
extern "C" void _s80268DD8_16();
extern "C" void _s80268DD8_17();
extern "C" void _s80268DD8_18();
extern "C" void _s80268DD8_19();
extern "C" void _s80268DD8_20();
extern "C" void _s80268DD8_21();
extern "C" void f_80268DD8() {}
