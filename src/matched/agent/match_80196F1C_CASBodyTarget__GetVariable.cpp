char* SimsAptMalloc(unsigned int size);

class CASBodyTarget {
public:
    char* GetVariable(char* name);
};

char* CASBodyTarget::GetVariable(char* name) {
    char* result = SimsAptMalloc(32);
    result[0] = 0;
    return result;
}
