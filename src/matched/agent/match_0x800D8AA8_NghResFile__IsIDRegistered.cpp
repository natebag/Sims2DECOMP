// 0x800D8AA8 (60B) NghResFile::IsIDRegistered(RegistryID)
// Constructs zero-initialized 16-byte RegistryNode on stack and forwards to FindNodeInRegistry.

typedef int RegistryID;
struct RegistryNode {
    int a, b, c, d;
    RegistryNode() : a(0), b(0), c(0), d(0) {}
};

class NghResFile {
public:
    int IsIDRegistered(RegistryID id);
    int FindNodeInRegistry(RegistryID id, RegistryNode& node);
};

int NghResFile::IsIDRegistered(RegistryID id)
{
    RegistryNode local;
    return FindNodeInRegistry(id, local);
}
