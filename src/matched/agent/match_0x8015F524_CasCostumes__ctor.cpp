// 0x8015F524 (56B) CasCostumes::CasCostumes()

class CasCostumes {
public:
    CasCostumes();
};

CasCostumes::CasCostumes() {
    volatile int frame_pad;
    int* p = (int*)this;
    int i = 1;
    do {
        p[0] = 0;
        int* aux = (int*)((char*)p + 8);
        p[1] = 0;
        aux[1] = 0;
        p += 4;
    } while (i-- != 0);
}
