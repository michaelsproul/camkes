/*
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */

#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>

void useri_provide_signature(const char * message, const char * signature) {
    printf("User: received signature for %s: %s\n", message, signature);
}

void useri_signature_refused(const char * message) {
    printf("User: signature refused for %s\n", message);
}

int run() {
    km_request_signature("bfdea00afabcd231");

    return 0;
}
