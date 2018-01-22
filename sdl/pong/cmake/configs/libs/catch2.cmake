ExternalProject_Add(
    catch2
    URL https://github.com/catchorg/Catch2/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/catch2
    CONFIGURE_COMMAND ""
    BUILD_COMMAND     ""
    INSTALL_COMMAND   ""
    TEST_COMMAND      ""
)

ExternalProject_Get_Property(catch2 source_dir)

include_directories(
    "${source_dir}/single_include"
)
