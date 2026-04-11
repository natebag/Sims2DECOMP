void GetJobHUDControlName(short id);

class HUDTarget {
public:
    int AddHUDControl(short a, short b, short& c);
};

int HUDTarget::AddHUDControl(short a, short b, short& c) {
    short id = (c = a);
    GetJobHUDControlName(id);
    return 1;
}
