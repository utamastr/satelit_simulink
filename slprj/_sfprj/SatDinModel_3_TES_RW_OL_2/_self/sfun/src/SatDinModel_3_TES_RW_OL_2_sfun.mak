# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


!include <ntwin32.mak>

MACHINE     = SatDinModel_3_TES_RW_OL_2
TARGET      = sfun
CHART_SRCS 	= \
     c2_SatDinModel_3_TES_RW_OL_2.c
MACHINE_SRC	= SatDinModel_3_TES_RW_OL_2_sfun.c
MACHINE_REG = SatDinModel_3_TES_RW_OL_2_sfun_registry.c
MEX_WRAPPER =
MAKEFILE    = SatDinModel_3_TES_RW_OL_2_sfun.mak
MATLAB_ROOT	= C:\Program Files (x86)\MATLAB\R2011a
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   = 
AUX_INCLUDES   = 
ML_INCLUDES     = /I "$(MATLAB_ROOT)\extern\include"
SL_INCLUDES     = /I "$(MATLAB_ROOT)\simulink\include"
SF_INCLUDES     = /I "C:\Program Files (x86)\MATLAB\R2011a\stateflow\c\mex\include" /I "C:\Program Files (x86)\MATLAB\R2011a\stateflow\c\debugger\include"

DSP_INCLUDES    =

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(ML_INCLUDES) $(SL_INCLUDES) $(SF_INCLUDES) $(DSP_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /nologo /MD $(COMPFLAGS)  
LDFLAGS = /nologo /dll /OPT:NOREF /export:mexFunction 
AUXLDFLAGS = 

#----------------------------- Source Files -----------------------------------

REQ_SRCS  = $(MACHINE_SRC) $(MACHINE_REG) $(MEX_WRAPPER) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = SatDinModel_3_TES_RW_OL_2_sfun.mol
SFCLIB = "C:\Program Files (x86)\MATLAB\R2011a\stateflow\c\mex\lib\win32\sfc_mexmsvc.lib" "C:\Program Files (x86)\MATLAB\R2011a\stateflow\c\debugger\lib\win32\sfc_debugmsvc.lib"
AUX_LNK_OBJS =
USER_LIBS =
LINK_MACHINE_LIBS =

DSP_LIBS    =
BLAS_LIBS   = "C:\Program Files (x86)\MATLAB\R2011a\extern\lib\win32\microsoft\libmwblascompat32.lib"

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw32
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

MEXLIB = "C:\Program Files (x86)\MATLAB\R2011a\extern\lib\win32\microsoft\libmx.lib" "C:\Program Files (x86)\MATLAB\R2011a\extern\lib\win32\microsoft\libmex.lib" "C:\Program Files (x86)\MATLAB\R2011a\extern\lib\win32\microsoft\libmat.lib" "C:\Program Files (x86)\MATLAB\R2011a\extern\lib\win32\microsoft\libfixedpoint.lib" "C:\Program Files (x86)\MATLAB\R2011a\extern\lib\win32\microsoft\libut.lib" "C:\Program Files (x86)\MATLAB\R2011a\extern\lib\win32\microsoft\libmwmathutil.lib" "C:\Program Files (x86)\MATLAB\R2011a\extern\lib\win32\microsoft\libemlrt.lib" "C:\Program Files (x86)\MATLAB\R2011a\lib\win32\libippmwipt.lib"

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS)
	@echo ### Linking ...
	$(LD) $(LDFLAGS) $(AUXLDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map" $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS) $(MEXLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) @$(OBJLIST_FILE)
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

