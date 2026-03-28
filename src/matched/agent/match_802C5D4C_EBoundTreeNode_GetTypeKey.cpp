struct TypeInfoBTN_Key {
    int pad[4];
    int key;
};

static TypeInfoBTN_Key s_typeInfo_k;

int EBoundTreeNode_GetTypeKey(void) {
    return s_typeInfo_k.key;
}
