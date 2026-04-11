typedef unsigned char u8;
u8* alloc_RParticle__Construct_RParticle_ptr(int, u8*);
u8* init_RParticle__Construct_RParticle_ptr(u8*);
u8* RParticle__Construct_RParticle_ptr(u8* ptr) {
    u8* obj = alloc_RParticle__Construct_RParticle_ptr(60, ptr);
    return init_RParticle__Construct_RParticle_ptr(obj);
}
