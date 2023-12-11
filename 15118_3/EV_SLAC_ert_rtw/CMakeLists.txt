###########################################################################
# CMakeLists.txt generated for component EV_SLAC
# Product type: executable
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(EV_SLAC)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()

# Define common variables that are used within the whole project.
set(SYSLIB_PREFIX $<IF:$<AND:$<BOOL:${WIN32}>,$<NOT:$<BOOL:${MINGW}>>>,lib,>)

###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR .. ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
set(MATLAB_ROOT /home/tuannt/MATLAB23b CACHE PATH "")

# Additional variables that are defined conditionally.
if("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

# Definition of target "EV_SLAC".
add_executable(EV_SLAC  ${MATLAB_ROOT}/toolbox/target/shared/embedded_utilities/common/src/ProtocolDecoderUtilities.c
    ${START_DIR}/EV_SLAC_ert_rtw/ert_main.c
    ${START_DIR}/EV_SLAC_ert_rtw/EV_SLAC.c
    ${START_DIR}/EV_SLAC_ert_rtw/EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_CNF.c
    ${START_DIR}/EV_SLAC_ert_rtw/EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_set_key_REQ.c
    ${START_DIR}/EV_SLAC_ert_rtw/EV_SLAC_V2GLinkSetupSLACMATCHEDpev_cm_slac_match.c
    ${START_DIR}/EV_SLAC_ert_rtw/EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONcheckAAG.c
    ${START_DIR}/EV_SLAC_ert_rtw/EV_SLAC_V2GLinkSetupSLACMATCHINGDESISIONpev_cm_atten_char_RSP.c
    ${START_DIR}/EV_SLAC_ert_rtw/EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_atten_char_IND.c
    ${START_DIR}/EV_SLAC_ert_rtw/EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_mnbc_sound.c
    ${START_DIR}/EV_SLAC_ert_rtw/EV_SLAC_V2GLinkSetupSLACMATCHINGSOUDING_SEQpev_cm_start_atten_char.c
    ${START_DIR}/EV_SLAC_ert_rtw/EV_SLAC_data.c
    ${START_DIR}/EV_SLAC_ert_rtw/rtGetInf.c
    ${START_DIR}/EV_SLAC_ert_rtw/rtGetNaN.c
    ${START_DIR}/EV_SLAC_ert_rtw/rt_nonfinite.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/slac_pev.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/assist.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/basespec.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/binout.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/__bswap.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/bytespec.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/checkfilename.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/checksum32.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/chrout.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/clr32bitmap.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/codelist.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/codename.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/config.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/dataspec.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/debug.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/decdecode.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/decout.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/decstring.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/desuid.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/efreopen.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/emalloc.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/error.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/extra.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/fdchecksum32.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/getargv.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/getoptv.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/gettimeofday.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/hexdecode.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/hexdump.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/hexencode.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/hexload.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/hexoffset.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/hexout.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/hexpeek.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/hexstring.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/hexview.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/ipv4spec.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/lookup.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/memdecr.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/memincr.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/memout.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/output.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/putoptv.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/regview32.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/reword.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/set32bitmap.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/strdecr.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/strfbits.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/strincr.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/synonym.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/todigit.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/typelist.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/typename.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/uintspec.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools/version.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/pev_amp_map.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/pev_cm_atten_char.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/pev_cm_mnbc_sound.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/pev_cm_set_key.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/pev_cm_slac_match.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/pev_cm_slac_param.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/pev_cm_start_atten_char.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/pev_cm_validate.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/slac_connect.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/slac_debug.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/slac_session.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac/slac_structs.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/ether/closechannel.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/ether/fcs.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/ether/gethwaddr.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/ether/getifname.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/ether/hostnics.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/ether/initchannel.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/ether/openchannel.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/ether/readpacket.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/ether/sendpacket.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/key/keys.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/key/putpwd.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/key/strnpwd.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/mme/EthernetHeader.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/mme/HomePlugHeader1.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/mme/readmessage.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/mme/sendmessage.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/mme/UnwantedMessage.c
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/plc/Devices.c
    ${START_DIR}/CustomCode/linuxUDP_portV6.c
    ${START_DIR}/CustomCode/MW_TCPSendReceive_portedV6.c
    ${START_DIR}/openV2G/appHandEXIDatatypes.c
    ${START_DIR}/openV2G/appHandEXIDatatypesDecoder.c
    ${START_DIR}/openV2G/appHandEXIDatatypesEncoder.c
    ${START_DIR}/openV2G/BitInputStream.c
    ${START_DIR}/openV2G/BitOutputStream.c
    ${START_DIR}/openV2G/ByteStream.c
    ${START_DIR}/openV2G/DecoderChannel.c
    ${START_DIR}/openV2G/EncoderChannel.c
    ${START_DIR}/openV2G/EXIHeaderDecoder.c
    ${START_DIR}/openV2G/EXIHeaderEncoder.c
    ${START_DIR}/openV2G/iso1EXIDatatypes.c
    ${START_DIR}/openV2G/iso1EXIDatatypesDecoder.c
    ${START_DIR}/openV2G/iso1EXIDatatypesEncoder.c
    ${START_DIR}/openV2G/main_databinder.c
    ${START_DIR}/openV2G/main_example.c
    ${START_DIR}/openV2G/MethodsBag.c
    ${START_DIR}/openV2G/v2gtp.c
    ${MATLAB_ROOT}/toolbox/target/codertarget/rtos/src/linuxinitialize.c)

# Set properties for target "EV_SLAC".
set_target_properties(EV_SLAC PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>")

# Specify language features required for target "EV_SLAC".
target_compile_features(EV_SLAC PUBLIC c_std_99)

# Specify compiler preprocessor definitions for target "EV_SLAC".
target_compile_definitions(EV_SLAC PRIVATE -DMODEL=EV_SLAC
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=1
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=0
    -DINTEGER_CODE=0
    -DMT=0
    -DARM_PROJECT
    -DSTACK_SIZE=64
    -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
    -DRT)

# Specify compiler flags for target "EV_SLAC".
target_compile_options(EV_SLAC PRIVATE -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9)

# Specify include directories for target "EV_SLAC".
target_include_directories(EV_SLAC PRIVATE ${START_DIR}
    ${MATLAB_ROOT}/toolbox/target/shared/embedded_utilities/common/include
    ${START_DIR}/EV_SLAC_ert_rtw
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/tools
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/slac
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/plc
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/mme
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/key
    /home/tuannt/Desktop/EVSE_hlc/SUTInterface/ISO15118If/SLAC/ether
    ${START_DIR}/CustomCode
    /home/tuannt/Downloads/gcc-arm-10.2-2020.11-x86_64-arm-none-linux-gnueabihf/arm-none-linux-gnueabihf/libc/usr/lib
    ${START_DIR}/openV2G
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common
    ${MATLAB_ROOT}/rtw/c/ert
    /home/tuannt/Documents/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arm_cortex_a/blocks/sfcn/include
    /home/tuannt/Documents/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arm_cortex_a/blocks/sfcn/src
    /home/tuannt/Documents/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arm_cortex_a/include
    ${MATLAB_ROOT}/toolbox/target/codertarget/rtos/inc)

# Specify linker flags for target "EV_SLAC".
target_link_libraries(EV_SLAC PRIVATE "-march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9")

# Specify library link dependencies for target "EV_SLAC".  CMake generator 
# expressions are used to create a CMakeLists.txt file that supports 
# multiple platforms with differently named system library dependencies.
target_link_libraries(EV_SLAC PRIVATE $<$<BOOL:${FOUND_LIBM}>:m>
    $<$<BOOL:${WIN32}>:kernel32>
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<BOOL:${WIN32}>:mswsock>
    $<$<BOOL:${WIN32}>:advapi32>)

# Extract DWARF debug symbols into a separate file when building 
# executable programs for Apple platforms.
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:EV_SLAC>;--flat,"
                "true"
        >)
    add_custom_command(TARGET EV_SLAC
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS EV_SLAC.dwarf)
endif()


###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET EV_SLAC POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:EV_SLAC>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(EV_SLAC)
endif()
