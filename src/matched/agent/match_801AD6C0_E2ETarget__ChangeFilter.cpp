int AtoI(char *);

class EyeToyClient {
public:
    static void ApplyPresetFilter(int);
};

class E2ETarget {
public:
    char _pad[0xC4];
    int m_filter;

    void ChangeFilter(char *, char *);
};

void E2ETarget::ChangeFilter(char *a, char *b) {
    int val = AtoI(b);
    if (val == 99) {
        val = -1;
    }
    m_filter = val;
    EyeToyClient::ApplyPresetFilter(val);
}
