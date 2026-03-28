// 0x801A0430 (104 bytes)
// CASRoommateTarget::GetVariable(char *)

class CASRoommateTarget { public: void GetVariable(char *); };

__attribute__((naked))
void CASRoommateTarget::GetVariable(char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7D1B78\n.long 0x7C9E2378\n.long 0x38600020\n.long 0x4BE66125\n.long 0x7C7F1B78\n.long 0x38000000\n.long 0x3C60803F\n.long 0x981F0000\n.long 0x3863D304\n.long 0x7FC4F378\n.long 0x480A33D1\n.long 0x2C030000\n.long 0x40820010\n.long 0x7FA3EB78\n.long 0x7FE4FB78\n.long 0x480000E1\n.long 0x7FE3FB78\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
