/* 0x80133430 ReconBuffer::ReconBool(bool *) (84B) */

class ReconBuffer {
public:
    void Recon8(signed char* p, int count);
    void ReconBool(int* b);
};

void ReconBuffer::ReconBool(int* b) {
    int v = *b;
    signed char tmp = (signed char)v;
    Recon8(&tmp, 1);
    *b = (tmp != 0) ? 1 : 0;
}
