// 0x8032520C (8 bytes)
class EMovieMan {
public:
    void SetMovieId(int p);
};

void EMovieMan::SetMovieId(int p) {
    *(int*)((char*)this + 0xD20) = p;
}
