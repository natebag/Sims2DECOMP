// 0x80112060 (68 bytes)
// ObjTestSim::ObjTestSim(cXPerson *, cXObject *)

class ObjTestSim { public: void ObjTestSim(cXPerson *, cXObject *); };

__attribute__((naked))
void ObjTestSim::ObjTestSim(cXPerson *, cXObject *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38000000\n.long 0x909E0000\n.long 0x901E0018\n.long 0x7CA42B78\n.long 0x901E0004\n.long 0x480000B1\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
