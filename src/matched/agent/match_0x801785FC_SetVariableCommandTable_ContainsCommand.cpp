// 0x801785FC (96B) SetVariableCommandTable::ContainsCommand(char*)
// Walk command list; strcmp each node->m_command vs cmd; return 1 on match, else 0.

extern "C" int strcmp(const char*, const char*);

struct CommandNode {
    int m_dummy;
    CommandNode* m_next;
    char* m_command;
};

struct CommandTable {
    CommandNode* m_head;
    int ContainsCommand(char* cmd);
};

int CommandTable::ContainsCommand(char* cmd) {
    CommandNode* node = m_head;
    while (node != 0) {
        if (strcmp(node->m_command, cmd) == 0)
            return 1;
        node = node->m_next;
    }
    return 0;
}
