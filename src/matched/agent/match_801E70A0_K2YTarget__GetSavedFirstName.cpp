static char s_savedFirstName[64];

class K2YTarget {
public:
    char* GetSavedFirstName(void);
};

char* K2YTarget::GetSavedFirstName(void) {
    return s_savedFirstName;
}
