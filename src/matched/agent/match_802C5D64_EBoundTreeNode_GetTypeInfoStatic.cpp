struct TypeInfo2 {
    int data[8];
};

static TypeInfo2 s_typeInfo2;

TypeInfo2* EBoundTreeNode_GetTypeInfoStatic(void) {
    return &s_typeInfo2;
}
