class INGTarget {
public:
    static int s_refrigeratorLevel;

    static int SetRefrigeratorLevel(int level);
};

int INGTarget::SetRefrigeratorLevel(int level) {
    int old = s_refrigeratorLevel;
    s_refrigeratorLevel = level;
    return old;
}
