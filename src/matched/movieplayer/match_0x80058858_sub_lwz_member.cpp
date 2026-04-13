// 0x80058858 MoviePlayerEndgameMovieState::SetFlowStateCurrent (36b)

struct W_80058858 { char pad[8]; void *field; };
extern void target_80058858(void*);

void sub_80058858(W_80058858 *self) {
    target_80058858(self->field);
}
