// ResourceBehaviorTree::Release (0x8022722c, 92 bytes)
// Ref-counted resource release - decrements reference and frees if needed

class IResource {
public:
    virtual void Release() = 0;
};

class ResourceBehaviorTree : public IResource {
    int m_refCount;  // at some offset

public:
    void Release() {
        // Simple ref-count decrement and cleanup
        m_refCount--;
        if (m_refCount <= 0) {
            delete this;  // ResourceBehaviorTree::operator delete will be called
        }
    }
};
