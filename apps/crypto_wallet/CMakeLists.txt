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

DeclareCAmkESComponent(User SOURCES components/User/src/user.c)
DeclareCAmkESComponent(KeyMaster SOURCES components/KeyMaster/src/key_master.c)
DeclareCAmkESComponent(Auth SOURCES components/Auth/src/auth.c)

DeclareCAmkESRootserver(crypto_wallet.camkes)
