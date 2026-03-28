struct TypeInfoBTN_RVer {
    int pad[5];
    unsigned short pad2;
    unsigned short readVersion;
};

static TypeInfoBTN_RVer s_typeInfo_rv;

unsigned short EBoundTreeNode_GetReadVersion(void) {
    return s_typeInfo_rv.readVersion;
}
