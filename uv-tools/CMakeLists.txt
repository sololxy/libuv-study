SET(SRCS "uv-tools.c")

add_executable("uv-tools" ${SRCS})
target_link_libraries("uv-tools" "libuv.lib")
if(WIN32)
    target_link_libraries("uv-tools" "ws2_32.lib") # 网络相关api
    target_link_libraries("uv-tools" "psapi.lib")  # 进程相关api
endif(WIN32)
