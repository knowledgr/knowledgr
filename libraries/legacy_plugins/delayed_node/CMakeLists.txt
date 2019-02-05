file(GLOB HEADERS "include/knowledgr/delayed_node/*.hpp")

add_library( knowledgr_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( knowledgr_delayed_node knowledgr_chain knowledgr_protocol knowledgr_app )
target_include_directories( knowledgr_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   knowledgr_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
