file(GLOB HEADERS "include/colab/account_statistics/*.hpp")

add_library( colab_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( colab_account_statistics colab_chain colab_protocol colab_app )
target_include_directories( colab_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   colab_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)