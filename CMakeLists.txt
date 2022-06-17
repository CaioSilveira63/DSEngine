cmake_minimum_required(VERSION 3.22)
project(DSEngine)
set(IS_PCENGINEE FALSE)

#0 = DS
#1 = PC
add_definitions( -DPlatformType=0 )

set(CMAKE_CXX_STANDARD 14)
set(IS_PCENGINE TRUE)

file(GLOB DSEngine
        engine/dsengine/*.h
        engine/dsengine/*.cpp
        )

file(GLOB PCEngine
        engine/pcengine/*.h
        engine/pcengine/*.cpp
        )
if (IS_PCENGINE)
    add_executable(DSEngine src/main.cpp engine/engine.h engine/engine.cpp ${PCEngine} engine/shared/ColorMaker.cpp engine/shared/ColorMaker.h)
    set(SFML_STATIC_LIBRARIES TRUE)
    find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
    target_link_libraries(DSEngine sfml-graphics sfml-audio)
else ()
    add_executable(DSEngine src/main.cpp engine/engine.h engine/engine.cpp ${DSEngine} engine/shared/ColorMaker.cpp engine/shared/ColorMaker.h)
endif (IS_PCENGINE)

