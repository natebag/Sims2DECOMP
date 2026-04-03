// cXObjectImpl::AllowIdleOptimization(void) (180 bytes)
// Check if idle optimization is allowed based on object state

class EdithVariableSet {
public:
    int operator[](int idx);
};

struct cXObjectImpl {
    char pad1[4];
    int m_parent;          // offset 4
    char pad2[36];
    EdithVariableSet m_vars;  // offset 40
    char pad3[136];
    int m_elementListStart; // offset 176
    int m_elementListEnd;   // offset 180

    int AllowIdleOptimization() {
        // Check if any elements in list have flag set (offset 16)
        int hasFlag = 0;
        for (int *elem = (int *)m_elementListStart; elem != (int *)m_elementListEnd; elem = (int *)((char *)elem + 108)) {
            int flag = *(int *)((char *)elem + 16);
            if (flag != 0) {
                hasFlag = 1;
                break;
            }
        }

        // Check parent state (virtual call at offset 792)
        int parentState = 0;
        if (m_parent != 0) {
            // Call parent's state getter
            // parentState = m_parent->GetState()  // virtual call
        }

        // Check variable 25
        int varVal = m_vars[25];
        if (varVal != 0) {
            return 0;  // Not allowed if variable set
        }

        if (hasFlag) {
            return 0;  // Not allowed if flag set
        }

        return 1;  // Optimization allowed
    }
};
