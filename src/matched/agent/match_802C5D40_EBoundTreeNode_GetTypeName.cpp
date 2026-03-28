struct TypeInfoBTN_Name {
    int pad[3];
    char* name;
};

static TypeInfoBTN_Name s_typeInfo_n;

char* EBoundTreeNode_GetTypeName(void) {
    return s_typeInfo_n.name;
}
