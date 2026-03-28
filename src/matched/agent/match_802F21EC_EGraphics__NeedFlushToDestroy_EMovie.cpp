class EMovie;
class EGraphics {
public:
    int NeedFlushToDestroy(EMovie *);
};
int EGraphics::NeedFlushToDestroy(EMovie *) { return 1; }
