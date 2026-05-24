// 0x800815D4 MUWrapper::ShowDialog(void) (684 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 0,0xc0(31); cmpwi 0,0; bne 0f; lis 4,-32707; addi 4,4,28136; bl _s800815D4_0; li 0,1; stw 0,0xc0(31); 0:; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); lis 8,-32707; addi 4,4,27500; addi 8,8,27520; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800815D4_1; lwz 9,0xac(31); li 0,0; stw 0,0x108(31); stw 0,0x114(31); cmpwi 9,1; stw 0,0x110(31); stw 0,0x10c(31); beq 1f; cmpwi 9,10; beq 1f; cmpwi 9,11; beq 1f; cmpwi 9,6; beq 1f; cmpwi 9,9; beq 1f; cmpwi 9,7; beq 1f; cmpwi 9,14; beq 1f; cmpwi 9,8; bne 2f; 1:; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); lis 8,-32707; addi 4,4,28032; addi 8,8,27540; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800815D4_2; li 0,1; stw 0,0x108(31); 2:; lwz 9,0xac(31); addi 0,9,-1; cmplwi 0,1; ble 3f; cmpwi 9,7; beq 3f; cmpwi 9,14; bne 4f; 3:; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); lis 8,-32707; addi 4,4,28032; addi 8,8,27548; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800815D4_3; li 0,1; stw 0,0x10c(31); 4:; lwz 0,0xac(31); cmpwi 0,2; bne 5f; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); lis 8,-32707; addi 4,4,28032; addi 8,8,27556; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800815D4_4; li 0,1; stw 0,0x110(31); 5:; lwz 9,0xac(31); addi 9,9,-10; cmplwi 9,1; bgt 6f; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); lis 8,-32707; addi 4,4,28032; addi 8,8,27564; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800815D4_5; li 0,1; stw 0,0x114(31); 6:; lis 30,-32697; lis 29,-32707; addi 30,30,24012; lis 8,-32707; lwz 3,0xb4(30); addi 8,8,27540; addi 4,29,28156; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800815D4_6; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27548; addi 4,29,28156; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800815D4_7; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27556; addi 4,29,28156; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800815D4_8; lwz 3,0xb4(30); lis 8,-32707; addi 4,29,28156; addi 8,8,27564; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800815D4_9; lwz 3,0xb4(30); lis 4,-32707; addi 4,4,27616; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s800815D4_10; lwz 9,0xa8(31); lwz 0,0x4(9); mr 3,9; ori 0,0,1; stw 0,0x4(9); bl _s800815D4_11; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800815D4_0();
extern "C" void _s800815D4_1();
extern "C" void _s800815D4_2();
extern "C" void _s800815D4_3();
extern "C" void _s800815D4_4();
extern "C" void _s800815D4_5();
extern "C" void _s800815D4_6();
extern "C" void _s800815D4_7();
extern "C" void _s800815D4_8();
extern "C" void _s800815D4_9();
extern "C" void _s800815D4_10();
extern "C" void _s800815D4_11();

struct MUWrapper {
    void ShowDialog();
};

void MUWrapper::ShowDialog() {
}
