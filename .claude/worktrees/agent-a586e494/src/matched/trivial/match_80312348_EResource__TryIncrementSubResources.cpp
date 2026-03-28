// 0x80312348 (8 bytes)
class EResource {
public:
    int TryIncrementSubResources();
};

int EResource::TryIncrementSubResources() {
    return 1;
}
