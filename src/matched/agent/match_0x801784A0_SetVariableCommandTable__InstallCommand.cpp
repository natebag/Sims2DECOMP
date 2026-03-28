/* SetVariableCommandTable::InstallCommand at 0x801784A0 (132b) */

extern int strcmp(const char*, const char*);

struct CBFunctor2_char_ptr_char_ptr {
    char data[8];
};

struct SetCommandNode {
    void* m_prev;
    SetCommandNode* m_next;
    char* m_name;
    CBFunctor2_char_ptr_char_ptr m_functor;
};

struct SetVariableCommandTable {
    SetCommandNode* m_head;
    int m_pad04;
    int m_count;

    int InstallCommand(char* name, CBFunctor2_char_ptr_char_ptr& functor);
    void AddNode(char* name, CBFunctor2_char_ptr_char_ptr& functor);
};

int SetVariableCommandTable::InstallCommand(char* name, CBFunctor2_char_ptr_char_ptr& functor) {
    if (m_count != 0) {
        SetCommandNode* node = m_head;
        while (node != 0) {
            if (strcmp(node->m_name, name) == 0) {
                return 0;
            }
            node = node->m_next;
        }
        AddNode(name, functor);
        return 1;
    }
    return 0;
}
