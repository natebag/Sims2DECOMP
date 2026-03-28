class EyeToyClient {
public:
    void SaveSessionToSlot(int);
};

class E2ETarget {
public:
    char _pad[0xC0];
    EyeToyClient *m_client;

    void SaveFrame(char *, char *);
};

void E2ETarget::SaveFrame(char *a, char *b) {
    m_client->SaveSessionToSlot((int)a);
}
