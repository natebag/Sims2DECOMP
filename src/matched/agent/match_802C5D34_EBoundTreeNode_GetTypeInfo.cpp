struct TypeInfo {
    int data[8];
};

static TypeInfo s_typeInfo;

TypeInfo* EBoundTreeNode_GetTypeInfo(void) {
    return &s_typeInfo;
}
