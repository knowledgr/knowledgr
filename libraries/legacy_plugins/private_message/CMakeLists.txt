file(GLOB HEADERS "include/colab/private_message/*.hpp")

add_library( colab_private_message
             private_message_plugin.cpp
           )

target_link_libraries( colab_private_message colab_chain colab_protocol colab_app )
target_include_directories( colab_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   colab_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
