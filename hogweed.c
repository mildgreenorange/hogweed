#include <string.h>
#include <math.h>

char* hogweedXor(char chMessage, int iCode) {
	for (int i = 0; chMessage[i] != '\0'; i += 1) {
		chMessage[i] = chMessage[i] ^ iCode;
	}
	
	return chMessage;
}

char* hogweedShift(char chMessage, int iCode) {
	for (int i = 0; chMessage[i] != '\0'; i += 1) {
		j = sizeof(iCode);
	
		if (i % 2 == 0) {
			chMessage[i] += iCode[j % i];
		} else {
			chMessage[i] += -iCode[j % i];
		}
	}
	
	return chMessage;
}

char* hogweedSpaceless(char chMessage) {
	for (int i = 0; chMessage[i] != '\0'; i += 1) {
		hogweedAdvance(chMessage, i);
	}
	
	return chMessage;
}

char* hogweedAdvance(char chMessage, int i) {
	if (chMessage[i] == ' ') {
		for (int j = i; chMessage[j] != '\0'; j += 1) {
			chMessage[j] = chMessage[j + 1];
		}
	}
	
	return chMessage;
}
