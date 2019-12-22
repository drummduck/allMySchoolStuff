# Install script for directory: /home/ndonalds/CS3505/A2/libharu

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_types.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_consts.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_version.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_annotation.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_catalog.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_conf.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_destination.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_doc.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_encoder.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_encrypt.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_encryptdict.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_error.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_ext_gstate.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_font.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_fontdef.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_gstate.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_image.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_info.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_list.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_mmgr.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_objects.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_outline.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_pages.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_page_label.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_streams.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_u3d.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_utils.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_pdfa.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_3dmeasure.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_exdata.h"
    "/home/ndonalds/CS3505/A2/libharu/include/hpdf_config.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES
    "/home/ndonalds/CS3505/A2/libharu/README"
    "/home/ndonalds/CS3505/A2/libharu/CHANGES"
    "/home/ndonalds/CS3505/A2/libharu/INSTALL"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "/home/ndonalds/CS3505/A2/libharu/if")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ndonalds/CS3505/A2/libharu/src/cmake_install.cmake")
  include("/home/ndonalds/CS3505/A2/libharu/demo/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ndonalds/CS3505/A2/libharu/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
