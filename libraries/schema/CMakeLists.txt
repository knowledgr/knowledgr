file(GLOB HEADERS "include/colab/schema/*.hpp")
add_library( colab_schema schema.cpp ${HEADERS} )
target_link_libraries( colab_schema fc )
target_include_directories( colab_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   colab_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/colab/schema" )
