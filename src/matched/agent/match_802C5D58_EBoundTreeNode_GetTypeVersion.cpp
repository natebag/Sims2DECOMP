struct TypeInfoBTN_Ver {
    int pad[5];
    unsigned short version;
};

static TypeInfoBTN_Ver s_typeInfo_v;

unsigned short EBoundTreeNode_GetTypeVersion(void) {
    return s_typeInfo_v.version;
}
