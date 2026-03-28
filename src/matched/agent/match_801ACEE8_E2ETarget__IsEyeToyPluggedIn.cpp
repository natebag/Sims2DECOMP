class EyeToyClient {
public:
    static int IsSessionEyeToyDisconnected(void);
};

class E2ETarget {
public:
    int IsEyeToyPluggedIn(void);
};

int E2ETarget::IsEyeToyPluggedIn(void) {
    return EyeToyClient::IsSessionEyeToyDisconnected() ^ 1;
}
