// 0x80032928 ESim::SetPlumbBobState(unsigned (604 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; bl _s80032928_0; mr 4,3; addi 3,31,968; bl _s80032928_1; mr 29,3; cmpwi 30,1; beq 5f; cmplwi 30,1; blt 0f; cmpwi 30,2; beq 9f; cmpwi 30,10; beq 15f; b 16f; 0:; lwz 0,0x3ec(31); cmpwi 0,1; bne 1f; lis 9,-32707; li 0,5; b 10f; 1:; cmpwi 0,2; bne 2f; lis 9,-32707; li 0,6; b 10f; 2:; cmpwi 0,0; beq 16f; cmpwi 0,5; beq 16f; cmpwi 0,6; beq 16f; cmpwi 0,7; beq 16f; cmpwi 29,0; beq 3f; lis 4,27935; mr 3,29; ori 4,4,2390; bl _s80032928_2; mr 3,29; li 4,0; bl _s80032928_3; 3:; lwz 3,0x3e8(31); cmpwi 3,0; beq 4f; bl _s80032928_4; li 0,0; stw 0,0x3e8(31); 4:; lis 3,-32692; lis 4,27935; addi 3,3,-27556; ori 4,4,2390; li 5,0; li 6,0; bl _s80032928_5; lis 9,-32707; li 0,7; b 14f; 5:; lwz 0,0x3ec(31); cmpwi 0,0; bne 6f; lis 9,-32707; li 0,3; b 10f; 6:; cmpwi 0,1; beq 16f; cmpwi 0,3; beq 16f; cmpwi 0,8; beq 16f; cmpwi 29,0; beq 7f; lis 4,20474; mr 3,29; ori 4,4,64824; bl _s80032928_6; mr 3,29; li 4,0; bl _s80032928_7; 7:; lwz 3,0x3e8(31); cmpwi 3,0; beq 8f; bl _s80032928_8; li 0,0; stw 0,0x3e8(31); 8:; lis 3,-32692; lis 4,20474; addi 3,3,-27556; ori 4,4,64824; li 5,0; li 6,0; bl _s80032928_9; lis 9,-32707; li 0,8; b 14f; 9:; lwz 0,0x3ec(31); cmpwi 0,0; bne 11f; lis 9,-32707; li 0,4; 10:; lfs f0,0x1188(9); stw 0,0x3ec(31); stfs f0,0x3f4(31); b 16f; 11:; cmpwi 0,2; beq 16f; cmpwi 0,4; beq 16f; cmpwi 0,9; beq 16f; cmpwi 29,0; beq 12f; lis 4,20474; mr 3,29; ori 4,4,64824; bl _s80032928_10; mr 3,29; li 4,0; bl _s80032928_11; 12:; lwz 3,0x3e8(31); cmpwi 3,0; beq 13f; bl _s80032928_12; li 0,0; stw 0,0x3e8(31); 13:; lis 3,-32692; lis 4,20474; addi 3,3,-27556; ori 4,4,64824; li 5,0; li 6,0; bl _s80032928_13; lis 9,-32707; li 0,9; 14:; lfs f0,0x1188(9); stw 3,0x3e8(31); stfs f0,0x3f4(31); stw 0,0x3ec(31); b 16f; 15:; stw 30,0x3ec(31); 16:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80032928_0();
extern "C" void _s80032928_1();
extern "C" void _s80032928_2();
extern "C" void _s80032928_3();
extern "C" void _s80032928_4();
extern "C" void _s80032928_5();
extern "C" void _s80032928_6();
extern "C" void _s80032928_7();
extern "C" void _s80032928_8();
extern "C" void _s80032928_9();
extern "C" void _s80032928_10();
extern "C" void _s80032928_11();
extern "C" void _s80032928_12();
extern "C" void _s80032928_13();

struct ESim {
    void SetPlumbBobState();
};

void ESim::SetPlumbBobState() {
}
