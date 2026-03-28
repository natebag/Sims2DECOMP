// 0x80177B44 (96 bytes)
// UIObjectBase::pushAptButtonFilterALL(int, char *)

class UIObjectBase { public: void pushAptButtonFilterALL(int, char *); };

__attribute__((naked))
void UIObjectBase::pushAptButtonFilterALL(int, char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7D1B78\n.long 0x4BFFFF0D\n.long 0x7C7E1B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000028\n.long 0x3BE00001\n.long 0x7FE5FB78\n.long 0x7FA3EB78\n.long 0x7FC4F378\n.long 0x3BFF0001\n.long 0x4BFFFF4D\n.long 0x281F0031\n.long 0x4081FFE8\n.long 0x7FC3F378\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
