class cFixedWorld {
public:
    virtual void dtor(int);
};

static cFixedWorld *gpWorld;

void DestroyTheWorld() {
    if (gpWorld != 0) {
        gpWorld->dtor(3);
    }
    gpWorld = 0;
}
