struct MovieState { unsigned char state; char pad[15]; };
MovieState s_movieState = { 1, {0} };
class ENgcMovie { public: unsigned char PlayerGetState(); };
unsigned char ENgcMovie::PlayerGetState() { return s_movieState.state; }
