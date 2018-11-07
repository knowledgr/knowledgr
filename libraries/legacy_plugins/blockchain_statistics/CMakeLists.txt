file(GLOB HEADERS "include/colab/blockchain_statistics/*.hpp")

add_library( colab_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( colab_blockchain_statistics colab_chain colab_protocol colab_app )
target_include_directories( colab_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   colab_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)