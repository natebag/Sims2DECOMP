char* SimsAptMalloc(unsigned int size);

class CASMiscTarget {
public:
    char* GetVariable(char* name);
};

char* CASMiscTarget::GetVariable(char* name) {
    char* result = SimsAptMalloc(32);
    result[0] = 0;
    return result;
}
