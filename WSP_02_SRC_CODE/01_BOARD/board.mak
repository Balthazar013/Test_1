#################################################################
#
# $Id: EvaMPC574XP.mak 17608 2014-02-03 14:53:52Z tojo2507 $
#
# This makefile contains board-specific definitions and rules.
#
# Copyright 1998-2014 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.
#
#################################################################

############ TOOLCHAIN mapping ##############
OS_TOOLCHAIN=$(TOOLCHAIN)

ifeq ($(TOOLCHAIN),dcc)
OS_TOOLCHAIN=diab
endif
ifeq ($(TOOLCHAIN),multi)
OS_TOOLCHAIN=ghs
endif
ifeq ($(TOOLCHAIN),gcc)
OS_TOOLCHAIN=gnu
endif

#############################################

#################################################################
# DEFINITIONS
ifeq ($(OS_BOARD_DIR), )
OS_BOARD_DIR=$(BOARD_PROJECT_PATH)
endif

CC_INCLUDE_PATH      += $(OS_BOARD_DIR)
CPP_INCLUDE_PATH     += $(OS_BOARD_DIR)
ASM_INCLUDE_PATH     += $(OS_BOARD_DIR)

CC_FILES_TO_BUILD += $(OS_BOARD_DIR)\board.c

ASM_FILES_TO_BUILD +=  $(OS_BOARD_DIR)\cstartup.s

EXCLUDE_MAKE_DEPEND  += $(OS_BOARD_DIR)\cstartup.s

######################## Defines for Linker file generation for Memory protected systems ############

ifeq ($(OS_TOOLCHAIN),ghs)
LOC_FILE_SUFFIX=ld
endif
ifeq ($(OS_TOOLCHAIN),diab)
LOC_FILE_SUFFIX=dld
endif
ifeq ($(OS_TOOLCHAIN),cw)
LOC_FILE_SUFFIX=lcf
endif
ifeq ($(OS_TOOLCHAIN),htgcc)
LOC_FILE_SUFFIX=ldconfig
endif

LOC_FILE= $(OS_BOARD_DIR)/MPC574XP_flash.$(LOC_FILE_SUFFIX)
