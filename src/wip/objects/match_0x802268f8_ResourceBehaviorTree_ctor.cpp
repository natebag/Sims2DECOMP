// ResourceBehaviorTree::ResourceBehaviorTree(void) (0x802268f8, 72 bytes)
// Initialize derived class from ObjectDataBehaviorTree

class ObjectDataBehaviorTree {
public:
    ObjectDataBehaviorTree();
};

class ResourceBehaviorTree : public ObjectDataBehaviorTree {
    char pad1[96];          // offsets that ObjectDataBehaviorTree covers
    int m_cachedResource;   // offset 96 (0x60)
    int m_cachedResField;   // offset 100 (0x64)

public:
    ResourceBehaviorTree() : ObjectDataBehaviorTree() {
        // Set vtable pointer to ResourceBehaviorTree vtable
        // Initialize resource fields to null
        m_cachedResource = 0;
        m_cachedResField = 0;
    }
};
