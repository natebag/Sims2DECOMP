// 0x801C3EC4 (32B) MDITarget::CleanupModelessDialogs(void)
// Thunk to MDITarget::DeleteAllModelessDialogs.

class MDITarget {
public:
    void CleanupModelessDialogs(void);
    void DeleteAllModelessDialogs(void);
};

void MDITarget::CleanupModelessDialogs(void) {
    DeleteAllModelessDialogs();
}
