cmake_minimum_required(VERSION 3.14)
project(QMultithreadedTCPServer)

set(CMAKE_CXX_STANDARD 14)

set(Qt5_DIR C:/Qt13-visualstudio/5.13.0/msvc2017_64/lib/cmake/Qt5)
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui network)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# qt files
set(project_src_files main.cpp SocketThread.cpp MultithreadedTCPServer.cpp )
set(project_header_files SocketThread.h MultithreadedTCPServer.h) # header files that inherts from QObject need to be scanned by MOC

# moc related
set(CMAKE_AUTOMOC ON)

qt5_wrap_cpp(project_src_moc ${project_header_files}) # because header files are where Q_Object is defined

add_executable(${PROJECT_NAME}  # ui files are not necessary here
        ${project_src_files}
        ${project_header_files}
        ${project_headers_wrapped}
        ${project_src_moc}
        )

target_link_libraries(${PROJECT_NAME} # PROJECT_NAME is case-sensitive
        PUBLIC
        Qt5::Core
        Qt5::Network
        )