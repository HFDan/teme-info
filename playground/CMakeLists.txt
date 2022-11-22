file(GLOB_RECURSE files "*.cpp")

foreach(file_path ${files})
    string(REPLACE ".cpp" "" new_name ${file_path}) 

    get_filename_component(filename ${new_name} NAME)
    get_filename_component(dir ${new_name} DIRECTORY)

    string(REPLACE "${CMAKE_SOURCE_DIR}/playground" "" new_dir ${dir})
    # string(REPLACE "/" "" new_dir ${new_dir})

    add_executable("${new_dir}${filename}" ${file_path} ${CMAKE_SOURCE_DIR}/include/debug.cpp)
    set_target_properties("${new_dir}${filename}" PROPERTIES OUTPUT_NAME "${filename}")
    set_target_properties("${new_dir}${filename}" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/playground/${new_dir}")
endforeach(file_path ${files})
