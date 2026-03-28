int AtoI(char *);

class EyeToyClient {
public:
    static void ApplyFunFrame(int);
};

class E2ETarget {
public:
    char _pad[0xBC];
    int m_funFrame;

    void ChangeFunFrame(char *, char *);
};

void E2ETarget::ChangeFunFrame(char *a, char *b) {
    int val = AtoI(b);
    if (val == 99) {
        val = -1;
    }
    m_funFrame = val;
    EyeToyClient::ApplyFunFrame(val);
}
