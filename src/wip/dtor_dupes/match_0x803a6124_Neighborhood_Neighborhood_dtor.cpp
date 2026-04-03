extern int VT_Neighborhood_Neighborhood[];
void del_Neighborhood_Neighborhood(void *);
void dtor_Neighborhood_Neighborhood(char *self, int __in_chrg) {
    *(int **)self = VT_Neighborhood_Neighborhood;
    if (__in_chrg & 1) {
        del_Neighborhood_Neighborhood(self);
    }
}
