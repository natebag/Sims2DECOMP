// 0x801E926C (68 bytes)
// GetVar_LockedStatus::Handler(char *)

class GetVar_LockedStatus { public: void Handler(char *); };

__attribute__((naked))
void GetVar_LockedStatus::Handler(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x8003000C\n.long 0x7C832378\n.long 0x2C000000\n.long 0x41820010\n.long 0x3D208040\n.long 0x38898798\n.long 0x4800000C\n.long 0x3D208040\n.long 0x3889879C\n.long 0x4805A645\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
