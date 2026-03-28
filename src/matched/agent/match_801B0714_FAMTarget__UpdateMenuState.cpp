int AtoI(char *);

class FAMTarget {
public:
    void UpdateMenuState(int state);
    void UpdateMenuState(char *a, char *b);
};

void FAMTarget::UpdateMenuState(char *a, char *b) {
    int state = AtoI(b);
    UpdateMenuState(state);
}
