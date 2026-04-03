/* 0x8039D5C8 (88 bytes) */
/* _Rb_global<bool>::_M_increment(_Rb_tree_node_base *) */

struct _Rb_tree_node_base {
    int _M_color;
    _Rb_tree_node_base* _M_parent;
    _Rb_tree_node_base* _M_left;
    _Rb_tree_node_base* _M_right;
};

template <typename T> class _Rb_global;
template <> class _Rb_global<bool> {
public:
    static _Rb_tree_node_base* _M_increment(_Rb_tree_node_base* __x);
};

_Rb_tree_node_base* _Rb_global<bool>::_M_increment(_Rb_tree_node_base* __x) {
    if (__x->_M_right) {
        __x = __x->_M_right;
        while (__x->_M_left) {
            __x = __x->_M_left;
        }
    } else {
        _Rb_tree_node_base* __y = __x->_M_parent;
        while (__x == __y->_M_right) {
            __x = __y;
            __y = __y->_M_parent;
        }
        if (__x->_M_right != __y) {
            __x = __y;
        }
    }
    return __x;
}
