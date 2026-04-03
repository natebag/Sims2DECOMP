// ResourceBehaviorTree::~ResourceBehaviorTree(void) (0x80226d14, 132 bytes)
// Destructor - clean up resource references

class EResource {
public:
    void DelRef();
};

class ObjectDataBehaviorTree {
public:
    virtual ~ObjectDataBehaviorTree();
};

class ResourceBehaviorTree : public ObjectDataBehaviorTree {
    char pad1[96];          // offsets 0-95
    EResource *m_resource;  // offset 96 (0x60)
    int m_resourceField;    // offset 100 (0x64)

public:
    ~ResourceBehaviorTree() {
        // Set vtable to ResourceBehaviorTree vtable
        int isDealloc = 1;  // from r30 parameter

        // Clean up resource references
        if (m_resourceField != 0) {
            if (m_resource != 0) {
                m_resource->DelRef();
                m_resource = 0;
            }
            m_resourceField = 0;
            m_resource = 0;
        }

        // Call base class destructor
        ObjectDataBehaviorTree::~ObjectDataBehaviorTree();

        // If allocated with new, delete this
        if (isDealloc & 1) {
            delete this;  // ResourceBehaviorTree::operator delete
        }
    }
};
