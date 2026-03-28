/* ObjectFolderImpl::GetBehaviorFinder(void) - 8 bytes */

struct BehaviorFinder {
    int dummy;
};

class ObjectFolderImpl {
public:
    char pad[0x04];
    BehaviorFinder m_behaviorFinder;

    BehaviorFinder* GetBehaviorFinder(void);
};

BehaviorFinder* ObjectFolderImpl::GetBehaviorFinder(void) {
    return &m_behaviorFinder;
}
