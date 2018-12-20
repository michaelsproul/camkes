#
# Copyright 2018, Data61
# Commonwealth Scientific and Industrial Research Organisation (CSIRO)
# ABN 41 687 119 230.
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(DATA61_BSD)
#

cmake_minimum_required(VERSION 3.7.2)

project(crypto_wallet C)

# Only support x86_64 at the moment
set(KernelArch x86 CACHE STRING "" FORCE)
set(KernelX86Sel4Arch x86_64 CACHE STRING "" FORCE)

RustAddLibrary(key_master
	SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/components/KeyMaster
	TARGET x86_64-sel4-none
	LIB_FILENAME libkey_master.a
)

DeclareCAmkESComponent(User SOURCES components/User/src/user.c)
DeclareCAmkESComponent(KeyMaster
    SOURCES components/KeyMaster/src/key_master.c
    LIBS key_master
)
DeclareCAmkESComponent(Auth SOURCES components/Auth/src/auth.c)

DeclareCAmkESRootserver(crypto_wallet.camkes)
