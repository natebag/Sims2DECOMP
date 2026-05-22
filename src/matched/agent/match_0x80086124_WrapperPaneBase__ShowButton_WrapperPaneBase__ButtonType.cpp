// 0x80086124 WrapperPaneBase::ShowButton(WrapperPaneBase::ButtonType) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; addi 9,3,64; rlwinm 0,31,2,0,29; li 11,256; lwzx 10,9,0; slw 11,11,31; lwz 0,0x4(10); ori 0,0,1; stw 0,0x4(10); lwz 9,0x4(3); and. 0,9,11; beq 2f; lwz 8,0x38(3); cmpwi 8,0; beq 0f; lis 9,-32697; lis 4,-32707; lwz 3,0x5e80(9); addi 4,4,29260; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80086124_0; b 1f; 0:; lis 9,-32697; lis 4,-32707; lis 8,-32707; lwz 3,0x5e80(9); addi 4,4,29260; addi 8,8,29280; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80086124_1; 1:; lis 30,-32697; lis 9,-32702; addi 30,30,24012; addi 9,9,15952; rlwinm 0,31,2,0,29; lwz 3,0xb4(30); lwzx 8,9,0; lis 4,-32707; addi 4,4,29416; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80086124_2; lis 4,-32707; lwz 3,0xb4(30); addi 4,4,29300; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s80086124_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80086124_0();
extern "C" void _s80086124_1();
extern "C" void _s80086124_2();
extern "C" void _s80086124_3();
extern "C" void f_80086124() {}
