ExternalProject_Add(
    catch
    URL https://github.com/catchorg/Catch2/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/catch
    CONFIGURE_COMMAND ""
    BUILD_COMMAND     ""
    INSTALL_COMMAND   ""
    LOG_DOWNLOAD ON
)

ExternalProject_Get_Property(catch source_dir)
set(CATCH_INCLUDE_DIR "${source_dir}/single_include" CACHE INTERNAL "Path to include folder for Catch")
