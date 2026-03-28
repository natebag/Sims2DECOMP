// 0x80112138 (80 bytes)
// ObjTestSim::SetStackObject(cXObject *)

class ObjTestSim { public: void SetStackObject(cXObject *); };

__attribute__((naked))
void ObjTestSim::SetStackObject(cXObject *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C842379\n.long 0x41820020\n.long 0x81240004\n.long 0xA8690210\n.long 0x80090214\n.long 0x7C641A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C641B78\n.long 0x909F0004\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
