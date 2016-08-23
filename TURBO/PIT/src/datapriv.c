#include "datapriv.h"

uint32_t rotl32 (uint32_t n, uint32_t c) {
	const unsigned int mask = (CHAR_BIT*sizeof(n)-1);
	c &= mask;
	return (n<<c) | (n>>( (-c)&mask ));
}

uint32_t rotr32 (uint32_t n, uint32_t c) {
	const unsigned int mask = (CHAR_BIT*sizeof(n)-1);
	c &= mask;
	return (n>>c) | (n<<( (-c)&mask ));
}

void dataPriv_expandCryptoVar(uint8_t *in, uint32_t *out) {
	// TODO verify the output of this function to that of the original pit executable
	// TODO what the heck is this algorithm called
	if (!in || ! out) {
		return;
	}
	out[0] = 0xb7e15163;
	int i;
	for (i = 1; i < 44; i++) {
		out[i] = out[i - 1] - 0x61c88647;
	}
	int tmp[4];
	for (i = 0; i < 16; i +=4) {
		tmp[i >> 2] = in[i] | (in[i + 1] << 8) | (in[i + 2] << 16) | (in[i + 3] << 24);
	}
	uint32_t j = 0;
	uint32_t k = 0;
	uint32_t l = 0;
	uint32_t m = 0;
	for (i = 131; i > 0; i--) {
		m = rotl32 (l + out[k] + m, 3);
		uint32_t v15 = m + l;
		if (v15 & 0x1f) {
			l = ((tmp[j] + v15) >> (32 - (v15 & 0x1f))) ^ ((tmp[j] + v15) << (v15 & 0x1f));
		} else {
			l = v15 + tmp[j];
		}
		out[k] = m;
		tmp[j] = l;
		k = ( k == 43 ) ? 0 : k + 1;
		j = ( j == 3 ) ? 0 : j +1;
	}
}
