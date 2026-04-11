// 0x800A76AC QuickStringSet::GetString (80b)

class QuickStringSet {
public:
    char* GetString(int);
    
    char pad[8];
    void** m_data;
};

char* QuickStringSet::GetString(int) {
    // Access m_data first to load into r9
    if (m_data == 0) return 0;
    
    // Now m_data is in a register, dereference it
    char** arr = (char**)*m_data;
    if (arr == 0) return 0;
    
    // Get count
    int n = ((int*)arr)[-1];
    
    // Compare with the parameter (still in r4)
    // Need to access the parameter somehow...
    
    return 0;  // Placeholder - need to figure out parameter access
}
