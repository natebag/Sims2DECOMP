// 0x8039FAB8 _Rb_global<bool>::_Rotate_left (96B)

struct _Rb_tree_node_base {
    int _M_color;
    _Rb_tree_node_base* _M_parent;
    _Rb_tree_node_base* _M_left;
    _Rb_tree_node_base* _M_right;
};

template <typename T> class _Rb_global;
template <> class _Rb_global<bool> {
public:
    static void _Rotate_left(_Rb_tree_node_base* __x, _Rb_tree_node_base*& __root);
};

void _Rb_global<bool>::_Rotate_left(_Rb_tree_node_base* __x, _Rb_tree_node_base*& __root) {
    _Rb_tree_node_base* __y = __x->_M_right;
    __x->_M_right = __y->_M_left;
    if (__y->_M_left != 0)
        __y->_M_left->_M_parent = __x;
    __y->_M_parent = __x->_M_parent;

    if (__x == __root)
        __root = __y;
    else if (__x == __x->_M_parent->_M_left)
        __x->_M_parent->_M_left = __y;
    else
        __x->_M_parent->_M_right = __y;

    __y->_M_left = __x;
    __x->_M_parent = __y;
}
