class EDL;
class EGraphics {
public:
    int NeedFlushToDestroy(EDL *);
};
int EGraphics::NeedFlushToDestroy(EDL *) { return 1; }
