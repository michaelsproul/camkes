#include <stdio.h>
#include <secp256k1.h>

int main() {
    secp256k1_context * ctxt = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);

    secp256k1_ecdsa_signature sig;

    unsigned char msg[32] = {
        0xff,
        0xfe,
        0xfd,
        0xfc,
        0xfb,
        0xfa,
        0xf9,
        0xf8,
        0xff,
        0xfe,
        0xfd,
        0xfc,
        0xfb,
        0xfa,
        0xf9,
        0xf8,
        0xff,
        0xfe,
        0xfd,
        0xfc,
        0xfb,
        0xfa,
        0xf9,
        0xf8,
        0xff,
        0xfe,
        0xfd,
        0xfc,
        0xfb,
        0xfa,
        0xf9,
        0xf8
    };

    // Dodgy: using the message hash as the secret key ;)
    int sig_ok = secp256k1_ecdsa_sign(ctxt, &sig, msg, msg, NULL, NULL);

    if (sig_ok) {
        printf("Signature is: ");
        for (int i = 0; i < 64; i++) {
            printf("%02x", sig.data[i]);
        }
        printf("\n");
    } else {
        printf("Signing failed\n");
    }
}
