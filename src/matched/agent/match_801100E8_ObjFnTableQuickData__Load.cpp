// 0x801100E8 (112 bytes)
// ObjFnTableQuickData::Load(iResFile *, short)

class ObjFnTableQuickData { public: void Load(iResFile *, short); };

__attribute__((naked))
void ObjFnTableQuickData::Load(iResFile *, short) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C842379\n.long 0x41820040\n.long 0x80640008\n.long 0x2C030000\n.long 0x41820034\n.long 0x8063002C\n.long 0x38800000\n.long 0x2C030000\n.long 0x41820008\n.long 0x8083FFFC\n.long 0x1C84007C\n.long 0x7C832214\n.long 0x48298571\n.long 0x907F000C\n.long 0x2C030000\n.long 0x38600000\n.long 0x40820008\n.long 0x3860FF9E\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
