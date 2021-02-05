cc_library(
	name = "hnsw",
	srcs = [
		"hnsw.cpp",
	],
	hdrs = [
		"hnsw.h",
	],
	visibility = ["//visibility:public"],
)

cc_binary(
	name = "hnsw_main",
	srcs = ["main.cpp"],
	deps = ["hnsw"],
	linkopts = [
		"-lm",
	],
)
