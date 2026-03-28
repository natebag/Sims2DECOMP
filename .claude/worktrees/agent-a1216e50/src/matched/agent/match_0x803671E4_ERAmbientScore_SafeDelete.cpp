/* ERAmbientScore::SafeDelete(void) - 0x803671E4 (64 bytes) */

struct ERAmbientScore {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERAmbientScore();
    static void SafeDelete(ERAmbientScore *p);
};

void ERAmbientScore::SafeDelete(ERAmbientScore *p)
{
    if (p) {
        delete p;
    }
}
