// 0x80022CB4 addRefList(vector<unsigned (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 27,0xc(1); stw 0,0x24(1); stw 12,0x8(1); mr 28,3; mr 29,4; lwz 4,0x4(28); lwz 3,0x0(28); subf 0,3,4; srawi. 31,0,2; beq 2f; lis 5,-32766; addi 5,5,11324; bl _s80022CB4_0; cmpwi 31,0; ble 2f; lis 27,-32693; cmpwi 4,29,0; li 30,0; 0:; lwz 9,0x0(28); addi 3,27,24536; li 5,0; li 6,0; lwzx 4,9,30; bl _s80022CB4_1; beq cr4,1f; lwz 9,0x0(29); addi 9,9,1; stw 9,0x0(29); 1:; addi 30,30,4; addic. 31,31,-1; bne 0b; 2:; lwz 0,0x24(1); lwz 12,0x8(1); mtspr 8,0; lmw 27,0xc(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s80022CB4_0();
extern "C" void _s80022CB4_1();
extern "C" void f_80022CB4() {}
