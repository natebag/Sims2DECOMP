// 0x8039FB18 (96 bytes)
// _Rb_global<bool>::_Rotate_right(_Rb_tree_node_base *, _Rb_tree_node_base *&)

class _Rb_global<bool> { public: void _Rotate_right(_Rb_tree_node_base *, _Rb_tree_node_base *&); };

__attribute__((naked))
void _Rb_global<bool>::_Rotate_right(_Rb_tree_node_base *, _Rb_tree_node_base *&) {
    asm volatile(".long 0x81630008\n.long 0x800B000C\n.long 0x90030008\n.long 0x812B000C\n.long 0x2C090000\n.long 0x41820008\n.long 0x90690004\n.long 0x80030004\n.long 0x900B0004\n.long 0x81240000\n.long 0x7C034800\n.long 0x4082000C\n.long 0x91640000\n.long 0x48000020\n.long 0x81230004\n.long 0x8009000C\n.long 0x7C030000\n.long 0x4082000C\n.long 0x9169000C\n.long 0x48000008\n.long 0x91690008\n.long 0x906B000C\n.long 0x91630004\n.long 0x4E800020");
}
