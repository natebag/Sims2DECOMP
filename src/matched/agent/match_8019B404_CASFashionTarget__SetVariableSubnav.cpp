// 0x8019B404 (96 bytes)
// CASFashionTarget::SetVariableSubnav(UIScreenID, int, int)

class CASFashionTarget { public: void SetVariableSubnav(UIScreenID, int, int); };

__attribute__((naked))
void CASFashionTarget::SetVariableSubnav(UIScreenID, int, int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFC10010\n.long 0x9001001C\n.long 0x7C7F1B78\n.long 0x7CDE3379\n.long 0x41820034\n.long 0x2C040011\n.long 0x4082002C\n.long 0x7CA42B78\n.long 0x807F008C\n.long 0x38A10008\n.long 0x48000031\n.long 0x2C030000\n.long 0x41820014\n.long 0x80A10008\n.long 0x7FE3FB78\n.long 0x7FC4F378\n.long 0x480002A1\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBC10010\n.long 0x38210018\n.long 0x4E800020");
}
