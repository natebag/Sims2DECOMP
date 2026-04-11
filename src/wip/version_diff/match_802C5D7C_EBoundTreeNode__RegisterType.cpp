typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EBoundTreeNodeName[];
extern int EBoundTreeNodeVtbl[];

extern void EBoundTreeNode_Ctor();
extern void EBoundTreeNode_Dtor();
extern void EBoundTreeNode_ReadWrite();
extern void EBoundTreeNode_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EBoundTreeNode {
    static void RegisterType(ushort typeId);
};

void EBoundTreeNode::RegisterType(ushort typeId) {
    RegisterTypeFunc(EBoundTreeNodeName, EBoundTreeNode_Ctor, EBoundTreeNode_Dtor, EBoundTreeNode_ReadWrite, typeId, EBoundTreeNode_SizeData, EBoundTreeNodeVtbl);
}
