// 0x8034F1EC get_private_index(unsigned (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32690; mr 11,3; addi 9,9,-14064; li 3,0; 0:; lwz 0,0x0(9); cmpwi 0,0; beq 1f; lwz 0,0x4(9); cmpw 11,0; beqlr; 1:; addi 3,3,1; addi 9,9,120; cmplwi 3,1; ble 0b; li 3,-1"
extern "C" int f_8034F1EC() {}
