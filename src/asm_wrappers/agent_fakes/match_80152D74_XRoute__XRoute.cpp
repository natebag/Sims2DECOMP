// 0x80152D74 (104 bytes)
// XRoute::XRoute(cXObject *, cXObject *, RoutingSlot *)

class XRoute { public: void XRoute(cXObject *, cXObject *, RoutingSlot *); };

__attribute__((naked))
void XRoute::XRoute(cXObject *, cXObject *, RoutingSlot *) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0xBF610014\n.long 0x9001002C\n.long 0x7C7E1B78\n.long 0x38000000\n.long 0x901E0000\n.long 0x393E0008\n.long 0x901E0004\n.long 0x7C9B2378\n.long 0x90090004\n.long 0x7CBD2B78\n.long 0x7CDC3378\n.long 0x387E0010\n.long 0x4BFEFBE9\n.long 0x7FC3F378\n.long 0x7F64DB78\n.long 0x7FA5EB78\n.long 0x7F86E378\n.long 0x4800001D\n.long 0x7FC3F378\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0xBB610014\n.long 0x38210028\n.long 0x4E800020");
}
