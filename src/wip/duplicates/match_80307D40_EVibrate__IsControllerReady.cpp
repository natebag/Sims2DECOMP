class EVibrate {
public:
    int IsControllerOn(unsigned char);
    int IsControllerReady(unsigned char);
};
int EVibrate::IsControllerReady(unsigned char id) { return IsControllerOn(id); }
