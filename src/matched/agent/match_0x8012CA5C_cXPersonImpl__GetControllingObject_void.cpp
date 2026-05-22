// 0x8012CA5C cXPersonImpl::GetControllingObject(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x420(3); lis 9,-21846; lwz 0,0x424(3); ori 9,9,43691; subf 0,11,0; mullw 0,0,9; srawi. 9,0,2; ble 0f; addi 9,9,-1; li 3,0; mulli 9,9,12; lwzx 9,11,9; cmpwi 9,0; beqlr; lwz 3,0x4(9); blr; 0:; lwz 9,0x4(3); lwz 3,0x0(9)"
extern "C" int f_8012CA5C() {}
