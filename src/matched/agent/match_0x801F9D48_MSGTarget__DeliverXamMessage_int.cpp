// 0x801F9D48 MSGTarget::DeliverXamMessage(int, (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,1; li 9,1; bne 0f; li 9,0; 0:; mulli 6,9,40; li 8,0; lis 9,-32700; addi 9,9,-25200; li 7,0; li 10,0; mr 11,6; 1:; lhzx 0,11,9; cmpw 0,4; bne 2f; li 7,1; b 3f; 2:; cmpwi 0,0; bne 3f; sthx 4,11,9; li 8,1; 3:; addi 10,10,1; addi 11,11,2; cmpwi 10,19; cmpwi 7,7,0; bgt 4f; cmpwi 8,0; bne 4f; beq cr7,1b; 4:; bnelr cr7; cmpwi 8,0; bnelr; lis 9,-32700; li 0,19; addi 9,9,-25200; mtspr 9,0; add 9,6,9; addi 9,9,2; 5:; lhz 0,0x0(9); sth 0,-2(9); addi 9,9,2; bdnz 5b; lis 9,-32700; addi 9,9,-25200; addi 9,9,38; sthx 4,9,6"
extern "C" void f_801F9D48() {}
