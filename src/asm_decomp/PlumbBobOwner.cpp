// PlumbBobOwner TU — 4 functions

struct PlumbBobStack;
struct PlumbBobOwner;

struct PlumbBob {
    char _pad[0x16C];
    PlumbBobOwner* owner;
    char _pad2[4];
    PlumbBobStack* stack;
};

struct PlumbBobOwner {
    void GetPlumbBob(int);
    void GrabPlumbBob(int, PlumbBobOwner*);
    void PushAndGrabPlumbBobOwner(int, PlumbBobOwner*);
    void PopPlumbBobOwner(int, PlumbBobOwner*);
};

struct PlumbBobStack {
    char _pad[368];
};

// External functions
extern void* __nw__FUl(unsigned long size);
extern void PlumbBob_Ctor(PlumbBob*);
extern void PlumbBob_SetPlayerColor(PlumbBob*, int);
extern void PlumbBobStack_Push(PlumbBobStack*, PlumbBob*);
extern void PlumbBobStack_Pop(PlumbBobStack*, PlumbBob*);

// SDA globals
extern PlumbBob* g_PlumbBobs[4];
extern int g_SomeFlag;

// 0x8005B7E8 (180 bytes)
void PlumbBobOwner::GetPlumbBob(int player) {
    PlumbBob* bob;
    if (player <= 1) {
        bob = g_PlumbBobs[player];
        if (bob == 0) {
            if (player == 0 || g_SomeFlag != 0) {
                bob = (PlumbBob*)__nw__FUl(508);
                PlumbBob_Ctor(bob);
                g_PlumbBobs[player] = bob;
                if (bob != 0) {
                    PlumbBob_SetPlayerColor(bob, player);
                }
            }
            bob = g_PlumbBobs[player];
        }
        if (bob != 0 && bob->owner == this) {
            return;
        }
    }
}

// 0x8005B89C (300 bytes)
void PlumbBobOwner::GrabPlumbBob(int player, PlumbBobOwner* newOwner) {
    PlumbBob* bob;
    PlumbBob* newBob;
    if (player <= 1) {
        bob = g_PlumbBobs[player];
        if (bob == 0) {
            if (player == 0 || g_SomeFlag != 0) {
                bob = (PlumbBob*)__nw__FUl(508);
                PlumbBob_Ctor(bob);
                g_PlumbBobs[player] = bob;
                if (bob != 0) {
                    PlumbBob_SetPlayerColor(bob, player);
                }
            }
            bob = g_PlumbBobs[player];
            if (bob == 0) {
                return;
            }
        }
        if (bob->owner != newOwner) {
            if (player <= 1) {
                newBob = g_PlumbBobs[player];
                if (newBob == 0) {
                    if (player == 0 || g_SomeFlag != 0) {
                        newBob = (PlumbBob*)__nw__FUl(508);
                        PlumbBob_Ctor(newBob);
                        g_PlumbBobs[player] = newBob;
                        if (newBob != 0) {
                            PlumbBob_SetPlayerColor(newBob, player);
                        }
                    }
                    newBob = g_PlumbBobs[player];
                    if (newBob == 0) {
                        return;
                    }
                }
                newBob->owner = newOwner;
            }
        }
    }
}

// 0x8005B9C8 (460 bytes)
void PlumbBobOwner::PushAndGrabPlumbBobOwner(int player, PlumbBobOwner* owner) {
    PlumbBob* bob;
    PlumbBobOwner* prevOwner;
    if (player <= 1) {
        bob = g_PlumbBobs[player];
        if (bob == 0) {
            if (player == 0 || g_SomeFlag != 0) {
                bob = (PlumbBob*)__nw__FUl(508);
                PlumbBob_Ctor(bob);
                g_PlumbBobs[player] = bob;
                if (bob != 0) {
                    PlumbBob_SetPlayerColor(bob, player);
                }
            }
            bob = g_PlumbBobs[player];
            if (bob == 0) {
                return;
            }
        }
        prevOwner = bob->owner;
        if (prevOwner != owner) {
            if (prevOwner != 0) {
                if (player <= 1) {
                    bob = g_PlumbBobs[player];
                    if (bob == 0) {
                        if (player == 0 || g_SomeFlag != 0) {
                            bob = (PlumbBob*)__nw__FUl(508);
                            PlumbBob_Ctor(bob);
                            g_PlumbBobs[player] = bob;
                            if (bob != 0) {
                                PlumbBob_SetPlayerColor(bob, player);
                            }
                        }
                        bob = g_PlumbBobs[player];
                        if (bob == 0) {
                            return;
                        }
                    }
                    if (bob->owner == prevOwner) {
                        PlumbBobStack_Push(bob->stack, bob);
                    }
                }
            }
            if (player <= 1) {
                bob = g_PlumbBobs[player];
                if (bob == 0) {
                    if (player == 0 || g_SomeFlag != 0) {
                        bob = (PlumbBob*)__nw__FUl(508);
                        PlumbBob_Ctor(bob);
                        g_PlumbBobs[player] = bob;
                        if (bob != 0) {
                            PlumbBob_SetPlayerColor(bob, player);
                        }
                    }
                    bob = g_PlumbBobs[player];
                    if (bob == 0) {
                        return;
                    }
                }
                bob->owner = owner;
            }
        }
    }
}

// 0x8005BB94 (468 bytes)
void PlumbBobOwner::PopPlumbBobOwner(int player, PlumbBobOwner* owner) {
    PlumbBob* bob;
    PlumbBobOwner* prevOwner;
    if (player <= 1) {
        bob = g_PlumbBobs[player];
        if (bob == 0) {
            if (player == 0 || g_SomeFlag != 0) {
                bob = (PlumbBob*)__nw__FUl(508);
                PlumbBob_Ctor(bob);
                g_PlumbBobs[player] = bob;
                if (bob != 0) {
                    PlumbBob_SetPlayerColor(bob, player);
                }
            }
            bob = g_PlumbBobs[player];
            if (bob == 0) {
                return;
            }
        }
        prevOwner = bob->owner;
        if (prevOwner == owner && prevOwner != 0) {
            if (player <= 1) {
                bob = g_PlumbBobs[player];
                if (bob == 0) {
                    if (player == 0 || g_SomeFlag != 0) {
                        bob = (PlumbBob*)__nw__FUl(508);
                        PlumbBob_Ctor(bob);
                        g_PlumbBobs[player] = bob;
                        if (bob != 0) {
                            PlumbBob_SetPlayerColor(bob, player);
                        }
                    }
                    bob = g_PlumbBobs[player];
                    if (bob == 0) {
                        return;
                    }
                }
                if (bob->owner == prevOwner) {
                    PlumbBobStack_Pop(bob->stack, bob);
                    prevOwner = bob->owner;
                }
            }
            if (player <= 1) {
                bob = g_PlumbBobs[player];
                if (bob == 0) {
                    if (player == 0 || g_SomeFlag != 0) {
                        bob = (PlumbBob*)__nw__FUl(508);
                        PlumbBob_Ctor(bob);
                        g_PlumbBobs[player] = bob;
                        if (bob != 0) {
                            PlumbBob_SetPlayerColor(bob, player);
                        }
                    }
                    bob = g_PlumbBobs[player];
                    if (bob == 0) {
                        return;
                    }
                }
                bob->owner = prevOwner;
            }
        }
    }
}
