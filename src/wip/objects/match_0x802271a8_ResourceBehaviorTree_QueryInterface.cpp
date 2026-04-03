// ResourceBehaviorTree::QueryInterface(unsigned int, void **) (0x802271a8, 112 bytes)
// COM-style interface query

class ObjectDataBehaviorTree {
public:
    virtual int QueryInterface(unsigned int iid, void **ppOut);
};

class ResourceBehaviorTree : public ObjectDataBehaviorTree {
    // vtable at offset 0

public:
    int QueryInterface(unsigned int iid, void **ppOut) {
        if (ppOut == 0) {
            return 0;
        }

        // Check for ResourceBehaviorTree IID (0x2BBBBAAA from lis/ori pattern)
        if (iid == 1 || iid == 0x2BBBBAAA) {
            // Call vtable function at known offset
            // This returns the interface pointer offset
            int offset = *(int*)*(int**)this;  // vtable[0]
            *ppOut = (char*)this + offset;
            return 1;
        }

        return 0;
    }
};
