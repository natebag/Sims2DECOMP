// 0x8039FE24 (112 bytes)
// _Rb_global<bool>::_M_decrement(_Rb_tree_node_base *)

class _Rb_global<bool> { public: void _M_decrement(_Rb_tree_node_base *); };

__attribute__((naked))
void _Rb_global<bool>::_M_decrement(_Rb_tree_node_base *) {
    asm volatile(".long 0x80030000\n.long 0x2C000000\n.long 0x4082001C\n.long 0x81230004\n.long 0x80090004\n.long 0x7C001800\n.long 0x4082000C\n.long 0x8063000C\n.long 0x4E800020\n.long 0x80030008\n.long 0x2C000000\n.long 0x4182002C\n.long 0x7C030378\n.long 0x8003000C\n.long 0x2C000000\n.long 0x4D820020\n.long 0x8063000C\n.long 0x8003000C\n.long 0x2C000000\n.long 0x4082FFF4\n.long 0x4E800020\n.long 0x7D234B78\n.long 0x81230004\n.long 0x80090008\n.long 0x7C030000\n.long 0x4182FFF0\n.long 0x7D234B78\n.long 0x4E800020");
}
