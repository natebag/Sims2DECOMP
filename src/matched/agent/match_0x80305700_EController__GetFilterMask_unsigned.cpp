// 0x80305700 EController::GetFilterMask(unsigned (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; cmpwi 4,-1; li 3,0; beq 2f; mr 3,31; li 30,0; bl _s80305700_0; lwz 11,0x8(31); addi 3,3,1; cmpw 3,11; bgt 1f; mulli 9,3,12; addi 9,9,20; add 9,9,31; 0:; lwz 0,0x0(9); addi 3,3,1; addi 9,9,12; cmpw 3,11; or 30,30,0; ble 0b; 1:; mr 3,30; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80305700_0();
extern "C" void f_80305700() {}
