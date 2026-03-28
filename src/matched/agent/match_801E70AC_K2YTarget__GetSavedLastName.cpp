static char s_savedLastName[64];

class K2YTarget {
public:
    char* GetSavedLastName(void);
};

char* K2YTarget::GetSavedLastName(void) {
    return s_savedLastName;
}
