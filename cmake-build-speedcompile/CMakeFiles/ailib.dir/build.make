# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Dmitry\Documents\GitHub\ailib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Dmitry\Documents\GitHub\ailib\cmake-build-speedcompile

# Include any dependencies generated for this target.
include CMakeFiles\ailib.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\ailib.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\ailib.dir\flags.make

CMakeFiles\ailib.dir\main.cpp.obj: CMakeFiles\ailib.dir\flags.make
CMakeFiles\ailib.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Dmitry\Documents\GitHub\ailib\cmake-build-speedcompile\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ailib.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ailib.dir\main.cpp.obj /FdCMakeFiles\ailib.dir\ /FS -c C:\Users\Dmitry\Documents\GitHub\ailib\main.cpp
<<

CMakeFiles\ailib.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ailib.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx64\x64\cl.exe > CMakeFiles\ailib.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Dmitry\Documents\GitHub\ailib\main.cpp
<<

CMakeFiles\ailib.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ailib.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ailib.dir\main.cpp.s /c C:\Users\Dmitry\Documents\GitHub\ailib\main.cpp
<<

CMakeFiles\ailib.dir\src\Models\Classifiers\KNearestNeighbor.cpp.obj: CMakeFiles\ailib.dir\flags.make
CMakeFiles\ailib.dir\src\Models\Classifiers\KNearestNeighbor.cpp.obj: ..\src\Models\Classifiers\KNearestNeighbor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Dmitry\Documents\GitHub\ailib\cmake-build-speedcompile\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ailib.dir/src/Models/Classifiers/KNearestNeighbor.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ailib.dir\src\Models\Classifiers\KNearestNeighbor.cpp.obj /FdCMakeFiles\ailib.dir\ /FS -c C:\Users\Dmitry\Documents\GitHub\ailib\src\Models\Classifiers\KNearestNeighbor.cpp
<<

CMakeFiles\ailib.dir\src\Models\Classifiers\KNearestNeighbor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ailib.dir/src/Models/Classifiers/KNearestNeighbor.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx64\x64\cl.exe > CMakeFiles\ailib.dir\src\Models\Classifiers\KNearestNeighbor.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Dmitry\Documents\GitHub\ailib\src\Models\Classifiers\KNearestNeighbor.cpp
<<

CMakeFiles\ailib.dir\src\Models\Classifiers\KNearestNeighbor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ailib.dir/src/Models/Classifiers/KNearestNeighbor.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ailib.dir\src\Models\Classifiers\KNearestNeighbor.cpp.s /c C:\Users\Dmitry\Documents\GitHub\ailib\src\Models\Classifiers\KNearestNeighbor.cpp
<<

CMakeFiles\ailib.dir\src\Math\Utils\DistanceMethods.cpp.obj: CMakeFiles\ailib.dir\flags.make
CMakeFiles\ailib.dir\src\Math\Utils\DistanceMethods.cpp.obj: ..\src\Math\Utils\DistanceMethods.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Dmitry\Documents\GitHub\ailib\cmake-build-speedcompile\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ailib.dir/src/Math/Utils/DistanceMethods.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ailib.dir\src\Math\Utils\DistanceMethods.cpp.obj /FdCMakeFiles\ailib.dir\ /FS -c C:\Users\Dmitry\Documents\GitHub\ailib\src\Math\Utils\DistanceMethods.cpp
<<

CMakeFiles\ailib.dir\src\Math\Utils\DistanceMethods.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ailib.dir/src/Math/Utils/DistanceMethods.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx64\x64\cl.exe > CMakeFiles\ailib.dir\src\Math\Utils\DistanceMethods.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Dmitry\Documents\GitHub\ailib\src\Math\Utils\DistanceMethods.cpp
<<

CMakeFiles\ailib.dir\src\Math\Utils\DistanceMethods.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ailib.dir/src/Math/Utils/DistanceMethods.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ailib.dir\src\Math\Utils\DistanceMethods.cpp.s /c C:\Users\Dmitry\Documents\GitHub\ailib\src\Math\Utils\DistanceMethods.cpp
<<

# Object files for target ailib
ailib_OBJECTS = \
"CMakeFiles\ailib.dir\main.cpp.obj" \
"CMakeFiles\ailib.dir\src\Models\Classifiers\KNearestNeighbor.cpp.obj" \
"CMakeFiles\ailib.dir\src\Math\Utils\DistanceMethods.cpp.obj"

# External object files for target ailib
ailib_EXTERNAL_OBJECTS =

ailib.exe: CMakeFiles\ailib.dir\main.cpp.obj
ailib.exe: CMakeFiles\ailib.dir\src\Models\Classifiers\KNearestNeighbor.cpp.obj
ailib.exe: CMakeFiles\ailib.dir\src\Math\Utils\DistanceMethods.cpp.obj
ailib.exe: CMakeFiles\ailib.dir\build.make
ailib.exe: CMakeFiles\ailib.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Dmitry\Documents\GitHub\ailib\cmake-build-speedcompile\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ailib.exe"
	"C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\ailib.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\ailib.dir\objects1.rsp @<<
 /out:ailib.exe /implib:ailib.lib /pdb:C:\Users\Dmitry\Documents\GitHub\ailib\cmake-build-speedcompile\ailib.pdb /version:0.0  /machine:x64 /INCREMENTAL:NO /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\ailib.dir\build: ailib.exe

.PHONY : CMakeFiles\ailib.dir\build

CMakeFiles\ailib.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ailib.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ailib.dir\clean

CMakeFiles\ailib.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Dmitry\Documents\GitHub\ailib C:\Users\Dmitry\Documents\GitHub\ailib C:\Users\Dmitry\Documents\GitHub\ailib\cmake-build-speedcompile C:\Users\Dmitry\Documents\GitHub\ailib\cmake-build-speedcompile C:\Users\Dmitry\Documents\GitHub\ailib\cmake-build-speedcompile\CMakeFiles\ailib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\ailib.dir\depend
