// 0x803365C0 InitAllMessageQueue(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32691; addi 3,9,14656; lwz 0,0xb0(3); cmpwi 0,0; bne 1f; addi 30,3,364; addi 31,3,256; 0:; mr 3,31; bl _s803365C0_0; addi 31,31,12; cmpw 31,30; ble 0b; 1:; lis 9,-32691; addi 31,9,15032; addi 30,31,32; 2:; mr 3,31; bl _s803365C0_1; addi 31,31,16; cmpw 31,30; ble 2b; lis 9,-32691; addi 3,9,14656; lbz 0,0xa7(3); cmpwi 0,0; beq 4f; addi 30,3,448; addi 31,3,424; 3:; mr 3,31; bl _s803365C0_2; addi 31,31,12; cmpw 31,30; ble 3b; 4:; lis 3,-32691; addi 4,13,-22540; addi 3,3,20288; li 5,1; bl _s803365C0_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803365C0_0();
extern "C" void _s803365C0_1();
extern "C" void _s803365C0_2();
extern "C" void _s803365C0_3();
extern "C" void f_803365C0() {}
