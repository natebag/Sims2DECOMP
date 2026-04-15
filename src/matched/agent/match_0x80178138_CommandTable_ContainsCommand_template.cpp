// CommandTable::ContainsCommand template — matches 4 functions:
// 0x80177554 UIAUDIO::ContainsEntry(char *)
// 0x80178ac4 GetLocalizableCommandTable::ContainsCommand(char *)
// 0x80178138 GetVariableCommandTable::ContainsCommand(char *)
// 0x801785fc SetVariableCommandTable::ContainsCommand(char *)

struct CommandNode {
    int m_dummy;
    CommandNode* m_next;
    char* m_command;
};

struct CommandTable {
    CommandNode* m_head;
    int ContainsCommand(char* cmd);
};

extern int strcmp(const char*, const char*);

int CommandTable::ContainsCommand(char* cmd) {
    CommandNode* node = m_head;
    while (node != 0) {
        if (strcmp(node->m_command, cmd) == 0)
            return 1;
        node = node->m_next;
    }
    return 0;
}
