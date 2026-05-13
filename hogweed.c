#include <string.h>
#include <math.h>

char* hogweedXor(char *chMessage, int iCode) {
    for (int i = 0; chMessage[i] != '\0'; i++) {
        chMessage[i] = chMessage[i] ^ iCode;
    }
    return chMessage;
}

char* hogweedShift(char *chMessage, int iCode) {
    unsigned char *bytes = (unsigned char*)&iCode;
    int j = sizeof(iCode);

    for (int i = 0; chMessage[i] != '\0'; i++) {
        int idx = (i == 0) ? 0 : (j % i);

        if (i % 2 == 0) {
            chMessage[i] += bytes[idx];
        } else {
            chMessage[i] -= bytes[idx];
        }
    }
    return chMessage;
}

char* hogweedSpaceless(char *chMessage) {
    for (int i = 0; chMessage[i] != '\0'; ) {
        if (chMessage[i] == ' ') {
            hogweedAdvance(chMessage, i);
        } else {
            i++;
        }
    }
    return chMessage;
}

char* hogweedAdvance(char *chMessage, int i) {
    if (chMessage[i] == ' ') {
        for (int j = i; chMessage[j] != '\0'; j++) {
            chMessage[j] = chMessage[j + 1];
        }
    }
    return chMessage;
}

char* hogweedMerge(char *chMessage, char *chCode) {
    for (int i = 0; i < sizeof(chMessage); i += 1) {
        int j = sizeof(chCode);
        chMessage[i] += chCode[j % i];
    }

    return chMessage;
}
