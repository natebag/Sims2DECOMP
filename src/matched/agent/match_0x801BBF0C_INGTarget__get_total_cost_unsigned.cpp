// 0x801BBF0C INGTarget::get_total_cost(unsigned (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,4; addi 3,3,480; mtspr 9,0; li 10,0; li 8,0; 0:; cmpwi 3,0; beq 1f; lwz 11,0x4(3); cmpwi 11,0; beq 1f; lwz 9,0x0(3); cmpwi 9,0; beq 1f; lha 0,0x2(9); addi 10,10,1; mullw 0,0,11; add 8,8,0; 1:; addi 3,3,8; bdnz 0b; cmpwi 4,0; beq 2f; stw 10,0x0(4); 2:; mr 3,8"
extern "C" void f_801BBF0C() {}
