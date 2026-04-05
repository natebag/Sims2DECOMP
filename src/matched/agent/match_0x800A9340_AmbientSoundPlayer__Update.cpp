typedef unsigned char u8;
u8* func1_amb(u8*);
void func2_amb(u8*);
void AmbientSoundPlayer_Update(u8* self) {
    func1_amb(self);
    func2_amb(self);
}
