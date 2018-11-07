file(GLOB HEADERS "include/colab/delayed_node/*.hpp")

add_library( colab_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( colab_delayed_node colab_chain colab_protocol colab_app )
target_include_directories( colab_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   colab_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
