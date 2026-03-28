struct VT_BTN {
    int pad[4];
    int* vtbl;
};

static VT_BTN s_vt_btn;

void EBoundTreeNode_Destruct(void** p) {
    *p = &s_vt_btn.vtbl;
}
