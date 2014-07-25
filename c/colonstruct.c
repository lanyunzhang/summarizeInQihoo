#include <stdio.h>
#include <limits.h>     /* for CHAR_BIT */

#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)

struct record {
    char *name;
    int refcount : 4;
    unsigned dirty : 1;
};

struct records {
    char *name;
    int refcount ;
    unsigned dirty;
};

int main(){
    printf("%d\n",sizeof(struct record));
    printf("%d\n",sizeof(struct records));

    int i = 7;
    printf("%d\n", i++ * i++);
}
