struct EVibrate {
    static int IsControllerOn(unsigned char id);
    static int IsControllerReady(unsigned char id);
};

int EVibrate::IsControllerReady(unsigned char id)
{
    return IsControllerOn(id);
}
