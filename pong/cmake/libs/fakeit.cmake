ExternalProject_Add(
    fakeit
    URL https://github.com/emersonmx/FakeIt/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/fakeit
    CONFIGURE_COMMAND ""
    BUILD_COMMAND     ""
    INSTALL_COMMAND   ""
    LOG_DOWNLOAD ON
)

ExternalProject_Get_Property(fakeit source_dir)
set(FAKEIT_INCLUDE_DIR "${source_dir}/single_header/catch" CACHE INTERNAL "Path to include folder for fakeit")
