class EyeToyClient {
public:
    int IsSessionEyeToyDisconnected();
};

class E2ETarget : public EyeToyClient {
public:
    int IsEyeToyPluggedIn();
};

int E2ETarget::IsEyeToyPluggedIn() {
    return IsSessionEyeToyDisconnected() ^ 1;
}
