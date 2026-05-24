// 0x80084AB4 WrapperPaneBase::Shutdown(void) (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 29,3; lwz 3,0x18(29); cmpwi 3,0; beq 0f; bl _s80084AB4_0; li 0,0; stw 0,0x18(29); 0:; mr 3,29; bl _s80084AB4_1; lwz 0,0x4(29); andi. 9,0,65280; beq 5f; lwz 8,0x38(29); cmpwi 8,0; beq 1f; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); addi 4,4,29260; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80084AB4_2; b 2f; 1:; lis 9,-32697; lis 4,-32707; lis 8,-32707; lwz 3,0x5e80(9); addi 4,4,29260; addi 8,8,29280; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80084AB4_3; 2:; lis 9,-32697; lis 11,-32702; addi 23,9,24012; addi 24,11,15952; li 30,0; addi 28,29,64; li 25,0; li 26,256; lis 27,-32707; li 31,0; 3:; stwx 25,31,28; slw 9,26,30; lwz 0,0x4(29); and. 11,0,9; beq 4f; lwz 3,0xb4(23); addi 4,27,29284; lwzx 8,31,24; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80084AB4_4; 4:; addi 30,30,1; addi 31,31,4; cmpwi 30,6; ble 3b; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); addi 4,4,29300; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s80084AB4_5; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"

extern "C" void _s80084AB4_0();
extern "C" void _s80084AB4_1();
extern "C" void _s80084AB4_2();
extern "C" void _s80084AB4_3();
extern "C" void _s80084AB4_4();
extern "C" void _s80084AB4_5();

struct WrapperPaneBase {
    void Shutdown();
};

void WrapperPaneBase::Shutdown() {
}
