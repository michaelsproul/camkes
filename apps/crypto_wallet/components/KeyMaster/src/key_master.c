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
#include <string.h>

void hello_world(void);

void kmi_request_signature(const char * message) {
    printf("KeyMaster: received %s\n", message);
    hello_world();
    if (auth_request_confirmation(message)) {
        user_provide_signature(message, "abcdef");
    } else {
        user_signature_refused(message);
    }
}
