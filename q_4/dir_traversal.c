#include <stdio.h>
#include <ftw.h>

int print_meta_data(const char *fpath, const struct stat *sb, int tflags, struct FTW *ftwbuf)
{
    if (tflags == FTW_SLN || tflags == FTW_SL) {
        return 0;
    }
    printf("%c %ju %s\n", (tflags == FTW_D ? 'D' : 'F'), sb->st_ino, fpath + ftwbuf->base);
    return 0;
}

void main(int argc, char **argv) {
    if (argc != 2) {
        printf("You have to give a path to a directory");
        return;
    }
    if (nftw(argv[1], print_meta_data, 4, FTW_PHYS)) {
        return;
    }
    return;
}

